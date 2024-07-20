#ifndef ZZ_BS_BATTERYDATA_H_
#define ZZ_BS_BATTERYDATA_H_

#include <stdint.h>

#include <iostream>
#include <sstream>

namespace zz
{
namespace battery_service
{

class BatteryRealtimeData
{
   public:
    std::string String()
    {
        std::ostringstream ostr;

        ostr << "total_current: " << total_current << "mA mb_current: " << current
             << "mA cell temperature: " << cell_temperature / 10 << "C voltage: " << voltage
             << "mV charging: " << is_charging << std::endl;

        return ostr.str();
    }

   public:
    uint16_t voltage;          // 电池电压 0~65525单位mV
    int16_t current;           // 电池电流 –32767~32768单位mA
    int16_t cell_temperature;  // 电芯温度 -2731~62804单位0.1摄氏度
    uint8_t capacity_percent;  // 容量百分比 0~100单位%
    uint16_t cell_vol[2];      // 各电芯电压，倍率：1000，取值范围0-65.535v
    uint8_t abnormal_code;
    bool is_charging;

    int32_t total_current;    // mA
    float board_temperature;  // battery temperature
    int32_t init_capacity_voltage;
    uint32_t voltage_now;
    bool is_abnormal;
};

class BatteryData
{
   public:
    std::string String()
    {
        std::string ret;
        char ret_temp[512];

        // product info
        snprintf(ret_temp, sizeof(ret_temp),
                 "%f, %d, %d, %d, "
                 "%.2f, %.2f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, "
                 "%d, %d, %d, %d, %d, %d, %d, %d, %d, "
                 "%d, %d, %f, %.2f, %.2f, %d, %d, %ld, %d, %d, %d,"
                 "%f, %f, %ld, %f, %f, %d, %.2f, %d",
                 // product info
                 coulomb_value, design_soc, design_vol, lifetime,

                 // realtime info
                 board_temperature, temperature, voltage, current, average_cur, average_vol, relative_soc, realtime_soc,
                 realtime_remain_soc, remain_soc, remain_time_s, realtime_data.capacity_percent,

                 // history info
                 max_vol, min_vol, max_charge_c, max_discharge_c, max_ave_discharge_c, max_ave_discharge_p, max_temp,
                 min_temp, runtime_statistics[0],

                 // misc
                 realtime_data.total_current, realtime_data.voltage, estimate_soc, calculate_soc, calc_soc_weight,
                 voltage_rate, is_flying, start_flying_timestamp, realtime_data.current, realtime_data.is_charging,
                 realtime_data.voltage_now,
                 // new add
                 calc_ws, correction_factor, time_between_frames, charg_calc_soc, av_charg_calc_soc, charg_flag,
                 health_factor, realtime_data.is_abnormal);
        ret = ret_temp;

        return ret;
    }

   public:
    // product info
    uint16_t full_charge_soc = 0;
    uint16_t design_soc = 0;
    uint16_t design_vol = 0;
    uint32_t application_ver = 0;
    uint8_t lifetime = 0;

    bool is_initialized = true;
    bool low_temperature = false;
    bool first_estimate = true;
    bool is_flex_point = false;
    bool reach_1st_inflection_point = false;
    bool normal_calu_capacity = false;
    float reach_1st_point_timestamp = 0.0f;
    bool inflection_point = false;
    int32_t average_vol_rate = 0;

    // realtime info

    float board_temperature = 0.0f;
    float temperature = 0.0f;
    uint32_t voltage = 0;
    int32_t current = 0;
    int32_t average_cur = 0;   // 前10s平均电流
    uint32_t average_vol = 0;  // 前10s平均电压
    int32_t relative_soc = 0;
    int32_t realtime_soc = 0;
    int32_t remain_soc = 0;
    int32_t realtime_remain_soc = 0;
    uint16_t remain_time_s = 0;
    uint16_t cell_vol[2] = {0};
    uint32_t battery_rsv = 0;
    uint8_t battery_sta = 0;
    bool is_charging = false;

    // new add
    float calc_ws = 0.0f;
    float coulomb_value = 0.0f;
    float correction_factor = 0.0f;
    uint64_t time_between_frames = 0.0f;
    float charg_calc_soc = 0.0f;
    float av_charg_calc_soc = 0.0f;
    bool charg_flag = false;
    float lowtemp_factor = 1.0f;  // low temperature capacity factor
    float health_factor = 1.0f;   // battery health

    // history info
    uint16_t max_vol = 0;
    uint16_t min_vol = 4200;
    uint32_t max_charge_c = 0;
    uint32_t max_discharge_c = 0;
    uint32_t max_ave_discharge_c = 0;
    uint32_t max_ave_discharge_p = 0;
    uint8_t max_temp = 0;
    uint8_t min_temp = 100;
    /*
      Total FW Runtime
      Time Spent in Ultra Temp
      Time Spent in Lowest Temp (UT-10℃)
      Time Spent in Lower Temp (10℃-20℃)
      Time Spent in Normal Temp (20℃-25℃)
      Time Spent in Higher Temp (25℃-30℃)
      Time Spent in Highest Temp (30℃-OT)
      Time Spent in Over Temp
    */
    uint32_t runtime_statistics[8] = {0};

    // alarm info
    uint16_t alarm_bits = 0;
    uint16_t notify_bits = 0;

    // misc
    BatteryRealtimeData realtime_data;
    uint16_t voltage_comp = 0;
    float estimate_soc = 0.0f;
    float calculate_soc = 0.0f;
    float calc_soc_weight = 0.7f;
    int32_t voltage_rate = 0;
    bool is_flying = false;
    uint64_t start_flying_timestamp = 0;
    bool full_flag = false;
    int32_t flex_point_time = 200;
};

}  // namespace battery_service
}  // namespace zz

#endif
