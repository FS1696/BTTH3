/**************************************

Mã sinh viên: 202419074
Họ tên: Vũ Thành Lâm

**************************************/

#include "ProjectTeam.h"
#include <iostream>
#include <iomanip>

// Constructor 1
ProjectTeam::ProjectTeam(const std::string& projectCode,
                         const std::string& projectName)
    : projectCode(projectCode),
      projectName(projectName),
      leader(nullptr)
{
    std::cout << "ProjectTeam constructor 1 called.\n";
}

// Constructor 2
ProjectTeam::ProjectTeam(const std::string& projectCode,
                         const std::string& projectName,
                         Employee& leader)
    : projectCode(projectCode),
      projectName(projectName),
      leader(&leader)
{
    // Tự động thêm trưởng nhóm vào danh sách thành viên
    members.push_back(&leader);

    std::cout << "ProjectTeam constructor 2 called.\n";
}

// Destructor
ProjectTeam::~ProjectTeam()
{
    // Chỉ hủy vector nội bộ.
    // Không được delete Employee vì ProjectTeam không sở hữu Employee.
    std::cout << "ProjectTeam destructor called: "
              << projectCode << " - "
              << projectName << "\n";
}

// Thêm thành viên
bool ProjectTeam::addMember(Employee& employee)
{
    // Không thêm nếu nhân sự đã tồn tại
    if (contains(employee.getId()))
    {
        return false;
    }

    members.push_back(&employee);
    return true;
}

// Thêm thành viên và có thể đặt làm trưởng nhóm
bool ProjectTeam::addMember(Employee& employee, bool makeLeader)
{
    // Không thêm nhân sự trùng
    if (contains(employee.getId()))
    {
        return false;
    }

    members.push_back(&employee);

    // Nếu được yêu cầu thì đặt nhân sự này làm trưởng nhóm
    if (makeLeader)
    {
        leader = &employee;
    }

    return true;
}

// Xóa thành viên theo mã nhân sự
bool ProjectTeam::removeMember(const std::string& employeeId)
{
    // Không được xóa trưởng nhóm hiện tại
    if (leader != nullptr && leader->getId() == employeeId)
    {
        return false;
    }

    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if ((*it)->getId() == employeeId)
        {
            members.erase(it);
            return true;
        }
    }

    return false;
}

// Đổi trưởng nhóm
bool ProjectTeam::changeLeader(Employee& employee)
{
    // Nếu chưa có trong nhóm thì tự động thêm vào
    if (!contains(employee.getId()))
    {
        members.push_back(&employee);
    }

    leader = &employee;

    return true;
}

// Kiểm tra nhân sự có trong nhóm hay không
bool ProjectTeam::contains(const std::string& employeeId) const
{
    for (Employee* employee : members)
    {
        if (employee->getId() == employeeId)
        {
            return true;
        }
    }

    return false;
}

// Tính tổng chi phí nhân sự hàng tháng
double ProjectTeam::calculateTotalMonthlyCost() const
{
    double total = 0;

    for (Employee* employee : members)
    {
        total += employee->calculateMonthlyCost();
    }

    return total;
}

// Hiển thị thông tin nhóm
void ProjectTeam::displayTeam() const
{
    std::cout << "\n========================================\n";
    std::cout << "Project Team\n";
    std::cout << "========================================\n";

    std::cout << "Project code: " << projectCode << "\n";
    std::cout << "Project name: " << projectName << "\n";

    if (leader != nullptr)
    {
        std::cout << "Leader: "
                  << leader->getId()
                  << " - "
                  << leader->getFullName()
                  << "\n";
    }
    else
    {
        std::cout << "Leader: None\n";
    }

    std::cout << "\nMembers:\n";

    if (members.empty())
    {
        std::cout << "No members.\n";
    }
    else
    {
        for (Employee* employee : members)
        {
            std::cout << "\n----------------------------------------\n";

            // Gọi hàm virtual -> thể hiện đa hình
            employee->displayInfo();
        }
    }

    std::cout << "\n----------------------------------------\n";
    std::cout << "Total monthly cost: "
              << std::fixed << std::setprecision(2)
              << calculateTotalMonthlyCost()
              << "\n";

    std::cout << "========================================\n";
}
