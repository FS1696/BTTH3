/**************************************

Mã sinh viên: 202419074
Họ tên: Vũ Thành Lâm

**************************************/

#include "Employee.h"
#include <iostream>
#include <stdexcept>

// Constructor mặc định
Employee::Employee()
    : id("UNKNOWN"),
      fullName("Unnamed employee"),
      baseSalary(0)
{
    std::cout << "Employee default constructor called.\n";
}

// Constructor có mã nhân sự và họ tên
Employee::Employee(const std::string& id,
                   const std::string& fullName)
    : id(id),
      fullName(fullName),
      baseSalary(0)
{
    if (id.empty())
    {
        throw std::invalid_argument("Employee ID cannot be empty.");
    }

    if (fullName.empty())
    {
        throw std::invalid_argument("Employee full name cannot be empty.");
    }

    std::cout << "Employee constructor 2 called.\n";
}

// Constructor đầy đủ thông tin
Employee::Employee(const std::string& id,
                   const std::string& fullName,
                   double baseSalary)
    : id(id),
      fullName(fullName),
      baseSalary(baseSalary)
{
    if (id.empty())
    {
        throw std::invalid_argument("Employee ID cannot be empty.");
    }

    if (fullName.empty())
    {
        throw std::invalid_argument("Employee full name cannot be empty.");
    }

    if (baseSalary < 0)
    {
        throw std::invalid_argument("Base salary cannot be negative.");
    }

    std::cout << "Employee constructor 3 called.\n";
}

// Destructor
Employee::~Employee()
{
    std::cout << "Employee destructor called: "
              << id << " - " << fullName << "\n";
}

// Tăng lương một số tiền cố định
void Employee::increaseSalary(double amount)
{
    if (amount <= 0)
    {
        throw std::invalid_argument(
            "Salary increase amount must be positive."
        );
    }

    baseSalary += amount;
}

// Tăng lương theo phần trăm hoặc số tiền cố định
void Employee::increaseSalary(double value, bool byPercentage)
{
    if (value <= 0)
    {
        throw std::invalid_argument(
            "Salary increase value must be positive."
        );
    }

    if (byPercentage)
    {
        baseSalary += baseSalary * value / 100.0;
    }
    else
    {
        baseSalary += value;
    }
}

// Getter mã nhân sự
std::string Employee::getId() const
{
    return id;
}

// Getter họ tên
std::string Employee::getFullName() const
{
    return fullName;
}

// Getter lương cơ bản
double Employee::getBaseSalary() const
{
    return baseSalary;
}

// Chi phí hàng tháng mặc định bằng lương cơ bản
double Employee::calculateMonthlyCost() const
{
    return baseSalary;
}

// Hiển thị thông tin
void Employee::displayInfo() const
{
    std::cout << "Employee Information\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Full name: " << fullName << "\n";
    std::cout << "Base salary: " << baseSalary << "\n";
}
