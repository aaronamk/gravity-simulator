## DESCRIPTION
* Simulator of Gravity in space using actual Physics values and equations (G = 6.674E-11)
* Uses C++ and the SFML graphics library
* General class hierarchy: `UserView <- Model <- Body`

## BUILD/RUN:
* Install dependencies: `make`, `cmake`, `gcc`, `sfml`
* Run:
```shell
git clone https://github.com/aaronamk/gravity-simulator.git
mkdir gravity-simulator/Debug
cd gravity-simulator/Debug
cmake ..
make
./gravity_sim
```
