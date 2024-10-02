#include "Fixed.hpp"

Fixed::Fixed():f_point(0)
{
    std::cout << "Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &other): f_point(other.f_point){
    std::cout << "Copy constructor called"<<std::endl;


}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" <<std::endl;
    if (this != &other)
    {
        this->f_point = other.f_point;

    }
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" <<std::endl;
    
    return this->f_point;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" <<std::endl;

    this->f_point = raw;
}

Fixed::~Fixed()
{
    std::cout << "destructor called"<< std::endl;
}