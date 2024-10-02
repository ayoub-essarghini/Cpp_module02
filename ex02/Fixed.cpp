#include "Fixed.hpp"

Fixed::Fixed() : f_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Default constructor called" << std::endl;
    this->f_point = num << fract_bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Default constructor called" << std::endl;
    this->f_point = roundf(num * (1 << fract_bits));
}

Fixed::Fixed(const Fixed &other) : f_point(other.f_point)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->f_point = other.f_point;
    }
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;

    return this->f_point;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;

    this->f_point = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(f_point) / (1 << fract_bits);
}

int Fixed::toInt(void) const
{
    return static_cast<int>(f_point >> fract_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}


Fixed::~Fixed()
{
    std::cout << "destructor called" << std::endl;
}



bool Fixed::operator>(const Fixed &other) const
{
    return f_point > other.f_point;
}

bool Fixed::operator<(const Fixed &other) const
{
    return f_point < other.f_point;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return f_point >= other.f_point;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return f_point <= other.f_point;
}

bool Fixed::operator==(const Fixed &other) const
{
    return f_point == other.f_point;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return f_point != other.f_point;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed fixed;
    fixed.setRawBits(f_point + other.f_point);
    return fixed;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed fixed;
    fixed.setRawBits(f_point - other.f_point);
    return fixed;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed fixed;
    fixed.setRawBits((f_point << fract_bits) / other.f_point);
    return fixed;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed fixed;
    fixed.setRawBits((f_point * other.f_point) >> fract_bits);
    return fixed;
}

Fixed &Fixed::operator++()
{
    this->f_point++;
    return *this;
}

Fixed &Fixed::operator--()
{
    this->f_point--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->f_point++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->f_point--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}