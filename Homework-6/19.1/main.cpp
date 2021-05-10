#include <iostream>
#include <string>

int const iMinSpeed = 0;
int const iMaxSpeed = 150;
float const fDeltaChecker = 0.01f;

float checkSpeed (float fCurrSpeed, float delta)
{
    if (fCurrSpeed + delta >= iMaxSpeed - fDeltaChecker)
    {
        std::cout << "Can't more quickly" << std::endl;
        return iMaxSpeed;
    }
    else
    if (fCurrSpeed + delta > iMinSpeed + fDeltaChecker)
        return (fCurrSpeed + delta);
    else
        return iMinSpeed;
}

int main() {
    float fDelta;
    float fSpeed = iMinSpeed;
    float fTotal;
    do
    {
        std::cout << "Delta speed:";
        std::cin >> fDelta;

        fTotal = checkSpeed (fSpeed, fDelta);
        std::cout << "Current speed: " << std::to_string ((int)fTotal) << " km/h" << std::endl;

        fSpeed = fTotal;
    } while (fSpeed > iMinSpeed + fDeltaChecker);

    std::cout << "Car is stopped!";
    return 0;
}
