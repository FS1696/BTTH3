/**************************************

Mã sinh viên: 202419074
Họ tên: Vũ Thành Lâm

**************************************/

#ifndef PROJECT_TEAM_H
#define PROJECT_TEAM_H

#include <string>
#include <vector>
#include "Employee.h"

class ProjectTeam
{
private:
    std::string projectCode;
    std::string projectName;

    // Không sở hữu Employee
    Employee* leader;

    // Danh sách thành viên, không sở hữu Employee
    std::vector<Employee*> members;

public:
    // Constructor 1: tạo nhóm chưa có trưởng nhóm
    ProjectTeam(const std::string& projectCode,
                const std::string& projectName);

    // Constructor 2: tạo nhóm có trưởng nhóm
    ProjectTeam(const std::string& projectCode,
                const std::string& projectName,
                Employee& leader);

    // Destructor
    ~ProjectTeam();

    // Nạp chồng addMember()
    bool addMember(Employee& employee);
    bool addMember(Employee& employee, bool makeLeader);

    // Xóa thành viên
    bool removeMember(const std::string& employeeId);

    // Đổi trưởng nhóm
    bool changeLeader(Employee& employee);

    // Kiểm tra nhân sự có trong nhóm hay không
    bool contains(const std::string& employeeId) const;

    // Tính tổng chi phí nhân sự hàng tháng
    double calculateTotalMonthlyCost() const;

    // Hiển thị thông tin nhóm
    void displayTeam() const;
};

#endif
