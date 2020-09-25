#include <iostream>
using namespace std;
class Vehicle
{
    public:
    Vehicle(float height, float weight)
    {
        _height = height;
        _weight = weight;
    }

    float RollResistance()
    {
        return 0.75 * _weight;
    }

    float WindResistance()
    {
        return 0.2 * _height;
    }

    float getFuel(float distance)           //REQ_ID_1
    {
        return distance * (RollResistance() + WindResistance()); 
    }

    private:
    float _weight = 0.0;
    float _height = 0.0;
};


class Truck : Vehicle
{
    public:

  Truck(float heightTruck, float weightTruck, float weightTrailer =0.0) : // without trailer
        Vehicle(heightTruck, weightTruck)
    {
        _weightTrailer = weightTrailer;
    }

    float TrailerResistance()
    {
        return 0.05 * _weightTrailer;
    }

    float getFuel(float distance)
    {
        return distance * (RollResistance() + WindResistance() + TrailerResistance());
    }

    private:
    float _weightTrailer = 0.0;
};


int main()
{
    Vehicle convertable(1.5, 500);
    Vehicle van(1.5, 4000);
    Truck without_trailer(4, 500);
    Truck with_trailer(4, 500, 30000);

    float distance = 42.195;

    cout << "Convertable Car fuel consumption: " << convertable.getFuel(distance) << endl;
    cout << "Van fuel consumption: " << van.getFuel(distance) << endl;
    cout << "Truck without Trailer fuel consumption: " << without_trailer.getFuel(distance) << endl;
    cout << "Truck with Trailer fuel consumption: " << with_trailer.getFuel(distance) << endl;

    return 0;
}