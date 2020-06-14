#include "myFunctions.hpp"

double calculateAngle(sf::Vector2f firstPos, sf::Vector2f secondPos){
    double angle = atan((secondPos.x-firstPos.x)/(firstPos.y-secondPos.y))*180/pi;

    if(secondPos.y>firstPos.y){
        if(secondPos.x>firstPos.x){
            angle+=180;
        }else{
            angle-=180;
        }
    }
    return angle;
}
double cordsDistance(sf::Vector2f firstPos, sf::Vector2f secondPos){
    return pow(pow(firstPos.x- secondPos.x, 2) + pow(firstPos.y - secondPos.y, 2), 0.5);
}
