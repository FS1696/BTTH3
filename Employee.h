
/**************************************

Mã sinh viên: 202419074
Họ tên: Vũ Thành Lâm

**************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
protected:
    std::string id;
    std::string fullName;
    double baseSalary;

public:
    // Constructor mặc định
    Employee();

    // Constructor có mã nhân sự và họ tên
    Employee(const std::string& id, const std::string& fullName);

    // Constructor đầy đủ thông tin
    Employee(const std::string& id,
             const std::string& fullName,
             double baseSalary);

    // Destructor ảo
    virtual ~Employee();

    // Nạp chồng phương thức tăng lương
    void increaseSalary(double amount);
    void increaseSalary(double value, bool byPercentage);

    // Getter
    std::string getId() const;
    std::string getFullName() const;
    double getBaseSalary() const;

    // Phương thức ảo tính chi phí hàng tháng
    virtual double calculateMonthlyCost() const;

    // Phương thức ảo hiển thị thông tin
    virtual void displayInfo() const;
};

#endif
