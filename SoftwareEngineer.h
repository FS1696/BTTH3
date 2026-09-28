/**************************************

Mã sinh viên: 202419074
Họ tên: Vũ Thành Lâm

**************************************/

#ifndef SOFTWARE_ENGINEER_H
#define SOFTWARE_ENGINEER_H

#include "Employee.h"

class SoftwareEngineer : public Employee
{
private:
    std::string primaryLanguage;
    double technicalAllowance;

public:
    // Constructor 1
    SoftwareEngineer(const std::string& id,
                     const std::string& fullName,
                     const std::string& primaryLanguage);

    // Constructor 2
    SoftwareEngineer(const std::string& id,
                     const std::string& fullName,
                     double baseSalary,
                     const std::string& primaryLanguage,
                     double technicalAllowance);

    // Destructor
    ~SoftwareEngineer() override;

    // Getter
    std::string getPrimaryLanguage() const;
    double getTechnicalAllowance() const;

    // Ghi đè phương thức của Employee
    double calculateMonthlyCost() const override;
    void displayInfo() const override;
};

#endif
