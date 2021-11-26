#include "verlet.h"
#include "MD_func.h"

Verlet::Verlet(MD_parameters& MD_para_in, UnitCell_pseudo &unit_in):
    mdp(MD_para_in),
    ucell(unit_in)
{
    std::cout << "verlet" << std::endl;

    allmass = new double [ucell.nat];
    pos = new ModuleBase::Vector3<double> [ucell.nat];
    vel = new ModuleBase::Vector3<double> [ucell.nat];
    ionmbl = new ModuleBase::Vector3<int> [ucell.nat];
    force = new ModuleBase::Vector3<double> [ucell.nat];
    virial.create(3,3);
    stress.create(3,3);

    // convert to a.u. unit
    mdp.dt/=ModuleBase::AU_to_FS;
	temperature_=mdp.tfirst/ModuleBase::Hartree_to_K;

    // LJ parameters
    mdp.rcut_lj *= ModuleBase::ANGSTROM_AU;
	mdp.epsilon_lj /= ModuleBase::Hartree_to_eV;
	mdp.sigma_lj *= ModuleBase::ANGSTROM_AU;

    step_rst_=0;

    frozen_freedom_ = MD_func::getMassMbl(ucell, mdp, allmass, ionmbl);
    MD_func::InitPos(ucell, pos);

    std::cout << mdp.rstMD << "  " << ucell.set_vel << std::endl;

    if(mdp.rstMD)
    {
        if(!MD_func::RestartMD(ucell.nat, vel, step_rst_))
        {
			std::cout<<"error in restart MD!"<<std::endl;
			return;
		}
    }
    else
    {
        MD_func::InitVel(ucell, temperature_, allmass, frozen_freedom_, ionmbl, vel);
    }

    step_=step_rst_;
}

Verlet::~Verlet()
{
    delete []allmass;
    delete []pos;
    delete []vel;
    delete []ionmbl;
    delete []force;
}

void Verlet::setup(){}

void Verlet::first_half(){}

void Verlet::second_half(){}

void Verlet::outputMD(){}