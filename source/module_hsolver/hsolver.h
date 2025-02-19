#ifndef HSOLVER_H
#define HSOLVER_H

#include "diagh.h"
#include "module_base/macros.h"
#include "module_elecstate/elecstate.h"
#include "module_hamilt_general/hamilt.h"
#include "module_hamilt_pw/hamilt_pwdft/wavefunc.h"
#include "module_hamilt_pw/hamilt_stodft/sto_wf.h"
#include "module_psi/psi.h"

#include <complex>

namespace hsolver
{

template <typename T, typename Device = base_device::DEVICE_CPU>
class HSolver
{
  private:
    using Real = typename GetTypeReal<T>::type;

  public:
    HSolver() {};

    // set diagethr according to drho (for lcao and lcao-in-pw, we suppose the error is zero and we set diagethr to 0)
    virtual Real set_diagethr(Real diag_ethr_in, const int istep, const int iter, const Real drho)
    {
        return 0.0;
    }
};

// reset diagethr according to drho and hsolver_error
double reset_diag_ethr(std::ofstream& ofs_running,
                       const std::string basis_type,
                       const std::string esolver_type,
                       const std::string precision_flag_in,
                       const double hsover_error,
                       const double drho_in,
                       const double diag_ethr_in,
                       const double nelec_in);

// calculate hsolver_error (for sdft, lcao and lcao-in-pw, we suppose the error is zero)
double cal_hsolve_error(const std::string basis_type,
                        const std::string esolver_type,
                        const double diag_ethr_in,
                        const double nelec_in);

} // namespace hsolver
#endif