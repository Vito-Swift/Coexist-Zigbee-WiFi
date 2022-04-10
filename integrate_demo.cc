#include <mysql_connection.h>
#include <chrono>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "CC2520.h"
#include <iostream>
#include <unistd.h>
#include <sys/time.h>

const char db_host[] = "192.168.1.100";
const char db_user[] = "grafanaReader";
const char db_passwd[] = "lxm274274";
const char db_name[] = "WISE";

struct db_handler {
    sql::Driver* driver;
    sql::Connection* conn;
    sql::Statement* statement;
};

double get_ts() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec + double(tp.tv_usec)/1000000;
}

void initialize_database(db_handler* handler) {
    handler->driver = get_driver_instance();
    handler->conn = handler->driver->connect(db_host, db_user, db_passwd);
    handler->conn->setSchema(db_name);
    handler->statement = handler->conn->createStatement();
    printf("Initialized SQL connection!\n");

    // initialize cca table;
    handler->statement->execute("DROP TABLE IF EXISTS CCA");
    handler->statement->execute("CREATE TABLE CCA" 
                                " (id INT AUTO_INCREMENT PRIMARY KEY,"
                                "  metric VARCHAR(3), value int, time DOUBLE);");
}

int main(void) {
    // initialize cc2520 firmware
    CC2520_Init();
    CC2520_Set_Channel(0, 11);
    // initialize database
    db_handler handler;
    initialize_database(&handler);
    
    sql::PreparedStatement* cca_prep_stmt;
    cca_prep_stmt = handler.conn->prepareStatement("INSERT INTO CCA(metric, value, time) VALUES (?,?,?)");
    while (1) {
        int cca_value = CC2520_Get_CCA(1);
        cca_prep_stmt->setString(1, "cca");
        cca_prep_stmt->setInt(2, cca_value);
        cca_prep_stmt->setDouble(3, get_ts());
        cca_prep_stmt->execute();
        
        usleep(50 * 1000);  // sleep x ms;
    }
}
