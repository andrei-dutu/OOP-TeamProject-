#ifndef EMPLOYEE_REPOSITORY_H
#define EMPLOYEE_REPOSITORY_H

#include <vector>
#include <string>
#include <optional>
#include "../Domain/employee.h"

namespace Repository {

    class EmployeeRepository {
    private:
        std::vector<Domain::Employee> all;

        std::optional<size_t> find_index_by_email(const std::string& email);

    public:
        void add(const Domain::Employee& employee);
        const std::vector<Domain::Employee>& get_all() const;
        std::vector<Domain::Employee>& get_all_ref();

        bool update_employee(const std::string& email, const Domain::Employee& updated_employee);
        bool set_active_status(const std::string& email, bool active);
        bool remove_employee(const std::string& email);
        bool set_admin_rights(const std::string& email, bool is_admin);
        bool reset_password(const std::string& email, const std::string& new_password = "default123");
    };

}

#endif


