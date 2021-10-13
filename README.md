# Model Predictive Control
Implementation of a variety of MPC controllers for temperature regulation of a building. Specifically, the controller tracks the reference temperatures while satisfying safety constraints at all time steps. Modeled using simplified heat flows betwwen the rooms and the environment, the dynamical system is affected by exogenous disturbances, e.g. solar radiation.
## Tasks

### Unconstrained Optimal Control
Design of a discrete-time infinite horizon Linear Quadratic Regulator for reference tracking.
Implementation of an heuristic LQR approach for controller tuning. This method aims at finding diagonal cost matrices such that the LQR minimizes the deviation from the desired stady-state.
### Constrained Optimal Control
#### MPC with Theoretical Closed-Loop Guarantees
Design of MPC controllers with feasibility and stability guarantees in closed loop. Closed loop trajectories will satisfy state and input constraints for all time steps and the target temperatures are asymptotically stable equilibrium points for the closed-loop system. Several variants to this problem are addressed, e.g. different terminal sets will be considered.
#### Soft Constraints
Design of a soft-constrained MPC controller.
Soft constraints are introduced to tackle the fact that in practice implementations the aformentioned optimization problems can be infeasible despite the theoretical guarantees on the constraints' satisfaction and stability due to model mismatch or unmodeled disturbances.
#### Offset-Free MPC
Disturbances in the heat flows are never known exactly. Therefore, estimation of the actual disturbances is needed to ensure offset-free reference tracking. In particular, in this subtask we have been dealing with a constant but unknown disturbance <i>d</i>.
#### FORCES PRO

