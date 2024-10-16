/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <stdio.h>
#include <stdexcept>

struct FileLogger {
    void log_transfer(long from, long to, double amount)
    {
        // --snip--
        printf("[file] %ld,%ld,%f\n", from, to, amount);
    }

};

struct ConsoleLogger {
    void log_transfer(long from, long to, double amount)
    {
        printf("[cons] %ld -> %ld:%f\n", from, to, amount);
    }
};

enum class LoggerType {
    Console,
    File
};

struct Bank {
    Bank() : type{LoggerType::Console} {}

    void set_logger(LoggerType new_type)
    {
        type = new_type;
    }

    void make_transfer(long from, long to, double amount)
    {
        //--snip--
        switch (type) {
        case LoggerType::Console:
            consoleLogger.log_transfer(from, to, amount);
            break;
        case LoggerType::File:
            fileLogger.log_transfer(from, to, amount);
            break;
        default:
            throw std::logic_error("Unknown Logger type encountered.");
        }
    };

   private:
    LoggerType type;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
};

/*****************************************************************************
 * | @fn     : XXXX
 * | @param  : - cmd 命令码
 * |           - dataPtr 发送的数据
 * |           - Len 发送的数据长度
 * | @return :
 * --------------
 * | @brief  : 发送请求到智能电池
 * |           通过串口2发送
 ******************************************************************************/
int main()
{
    printf("----------------begain------------------\n");
    Bank bank;
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
    bank.set_logger(LoggerType::File);
    bank.make_transfer(3000, 2000, 75.00);

    printf("-----------------end-------------------\n");
}

/***********************************************************
 * end of file
 **********************************************************/
