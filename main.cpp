/**************************************

Mã sinh viên: 202419074
Họ tên: Vũ Thành Lâm

**************************************/

#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "SoftwareEngineer.h"
#include "ProjectTeam.h"

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    cout << "========================================\n";
    cout << "        LAB 03-04: OVERLOADING\n";
    cout << "========================================\n";

    // =========================================================
    // 1. Tạo hai Employee bằng hai constructor khác nhau
    // =========================================================

    cout << "\n========== 1. CREATE EMPLOYEES ==========\n";

    // Employee constructor 1
    Employee employee1;

    // Employee constructor 2
    Employee employee2("E002", "Tran Thi B");

    // Gán lương cho employee2 bằng constructor 3 sẽ được
    // kiểm thử ở employee3 bên dưới.
    Employee employee3("E003", "Le Van C", 1500);

    cout << "\nEmployee 1:\n";
    employee1.displayInfo();

    cout << "\nEmployee 2:\n";
    employee2.displayInfo();

    cout << "\nEmployee 3:\n";
    employee3.displayInfo();


    // =========================================================
    // 2. Tạo hai SoftwareEngineer bằng hai constructor khác nhau
    // =========================================================

    cout << "\n========== 2. CREATE SOFTWARE ENGINEERS ==========\n";

    // SoftwareEngineer constructor 1
    SoftwareEngineer engineer1(
        "SE001",
        "Nguyen Van A",
        "C++"
    );

    // SoftwareEngineer constructor 2
    SoftwareEngineer engineer2(
        "SE002",
        "Pham Van D",
        2000,
        "Java",
        500
    );

    cout << "\nSoftware Engineer 1:\n";
    engineer1.displayInfo();

    cout << "\nSoftware Engineer 2:\n";
    engineer2.displayInfo();


    // =========================================================
    // 3. Tăng lương một nhân sự bằng số tiền cố định
    // =========================================================

    cout << "\n========== 3. INCREASE SALARY BY FIXED AMOUNT ==========\n";

    cout << "Employee 2 salary before: "
         << employee2.getBaseSalary() << "\n";

    employee2.increaseSalary(500);

    cout << "Employee 2 salary after +500: "
         << employee2.getBaseSalary() << "\n";


    // =========================================================
    // 4. Tăng lương một nhân sự khác theo phần trăm
    // =========================================================

    cout << "\n========== 4. INCREASE SALARY BY PERCENTAGE ==========\n";

    cout << "Employee 3 salary before: "
         << employee3.getBaseSalary() << "\n";

    employee3.increaseSalary(10, true);

    cout << "Employee 3 salary after +10%: "
         << employee3.getBaseSalary() << "\n";


    // =========================================================
    // 5. Tạo nhóm dự án không có trưởng nhóm
    // =========================================================

    cout << "\n========== 5. CREATE PROJECT TEAM ==========\n";

    ProjectTeam team1(
        "P001",
        "E-Commerce System"
    );

    team1.displayTeam();


    // =========================================================
    // 6. Thêm một nhân sự vào nhóm bằng addMember(employee)
    // =========================================================

    cout << "\n========== 6. ADD MEMBER ==========\n";

    if (team1.addMember(employee1))
    {
        cout << "Employee 1 added successfully.\n";
    }
    else
    {
        cout << "Employee 1 could not be added.\n";
    }


    // =========================================================
    // 7. Thêm một kỹ sư bằng addMember(employee, true)
    //    để đặt làm trưởng nhóm
    // =========================================================

    cout << "\n========== 7. ADD ENGINEER AS LEADER ==========\n";

    if (team1.addMember(engineer1, true))
    {
        cout << "Engineer 1 added and set as leader.\n";
    }
    else
    {
        cout << "Engineer 1 could not be added.\n";
    }

    team1.displayTeam();


    // =========================================================
    // 8. Thử thêm lại một thành viên đã tồn tại
    // =========================================================

    cout << "\n========== 8. ADD DUPLICATE MEMBER ==========\n";

    if (team1.addMember(employee1))
    {
        cout << "Employee 1 was added again.\n";
    }
    else
    {
        cout << "Employee 1 already exists. Add rejected.\n";
    }


    // =========================================================
    // 9. Hiển thị danh sách bằng lời gọi đa hình
    // =========================================================

    cout << "\n========== 9. POLYMORPHISM ==========\n";

    team1.displayTeam();


    // =========================================================
    // 10. Tính tổng chi phí nhân sự hằng tháng
    // =========================================================

    cout << "\n========== 10. TOTAL MONTHLY COST ==========\n";

    cout << "Total monthly cost of team 1: "
         << team1.calculateTotalMonthlyCost()
         << "\n";


    // =========================================================
    // 11. Thử xóa trưởng nhóm hiện tại
    //     và kiểm tra thao tác bị từ chối
    // =========================================================

    cout << "\n========== 11. REMOVE CURRENT LEADER ==========\n";

    if (team1.removeMember(engineer1.getId()))
    {
        cout << "Leader removed.\n";
    }
    else
    {
        cout << "Cannot remove current leader.\n";
    }


    // =========================================================
    // 12. Đổi trưởng nhóm rồi xóa người từng là trưởng nhóm
    // =========================================================

    cout << "\n========== 12. CHANGE LEADER AND REMOVE OLD LEADER ==========\n";

    // Đổi employee1 thành trưởng nhóm
    if (team1.changeLeader(employee1))
    {
        cout << "Employee 1 is now the new leader.\n";
    }

    // engineer1 hiện không còn là leader
    // nên có thể xóa engineer1
    if (team1.removeMember(engineer1.getId()))
    {
        cout << "Old leader Engineer 1 removed successfully.\n";
    }
    else
    {
        cout << "Could not remove old leader.\n";
    }

    team1.displayTeam();


    // =========================================================
    // 13. Tạo nhóm thứ hai và thêm một nhân sự đã có ở nhóm thứ nhất
    //     để chứng minh quan hệ kết tập nhiều nhóm
    // =========================================================

    cout << "\n========== 13. SECOND PROJECT TEAM ==========\n";

    {
         ProjectTeam team2(
            "P002",
            "Banking Management System"
        );

        // employee1 đã có trong team1
        // và bây giờ tiếp tục được thêm vào team2
        if (team2.addMember(employee1))
        {
            cout << "Employee 1 added to team 2 successfully.\n";
        }

        // Thêm thêm một SoftwareEngineer
        if (team2.addMember(engineer2))
        {
            cout << "Engineer 2 added to team 2 successfully.\n";
        }

        team2.displayTeam();

        cout << "\nEmployee 1 is in team 1: "
             << (team1.contains(employee1.getId()) ? "YES" : "NO")
             << "\n";

        cout << "Employee 1 is in team 2: "
             << (team2.contains(employee1.getId()) ? "YES" : "NO")
             << "\n";


    // =====================================================
    // 14. Hủy nhóm thứ hai bằng cách kết thúc khối lệnh
    // =====================================================

    cout << "\n========== 14. DESTROY TEAM 2 ==========\n";
    cout << "Leaving local scope...\n";
}


    // =========================================================
    // 15. Chứng minh nhân sự của nhóm thứ hai vẫn tồn tại
    //     sau khi nhóm bị hủy
    // =========================================================

    cout << "\n========== 15. EMPLOYEES STILL EXIST ==========\n";

    cout << "Employee 1 after team 2 destruction:\n";
    employee1.displayInfo();

    cout << "\nEngineer 2 after team 2 destruction:\n";
    engineer2.displayInfo();

    cout << "\nThe employee objects still exist because "
         << "ProjectTeam does not own them.\n";

    // =========================================================
    // FINAL RESULT
    // =========================================================

    cout << "\n========================================\n";
    cout << "        TEST FINISHED\n";
    cout << "========================================\n";

    return 0;
}
