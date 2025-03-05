



#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

/*
 * SYS_LIGHTWEIGHT_PROT==1： 如果希望在缓冲区分配、释放和内存分配、释放期间对某些关键
 * 区域进行任务间保护
 */
#define SYS_LIGHTWEIGHT_PROT     0


/*
 * NO_SYS==1： 无操作系统模拟层
 */
#define NO_SYS                       1                                                  //(1)


/*
 * NO_SYS_NO_TIMERS==1： 无操作系统定时器
 */
#define NO_SYS_NO_TIMERS          0


/* ---------- 内存选项 ---------- */
/* MEM_ALIGNMENT：应设置为编译LwIP的CPU的对齐方式，如2、4、8字节等 */
#define MEM_ALIGNMENT              4                                                    //(2)


/* MEM_SIZE： 堆内存大小 */
#define MEM_SIZE                    (30*1024)                                           //(3)


/* MEMP_NUM_PBUF： 内存池中pbuf的数量。如果应用程序从ROM（或其他静态存储器
     发送大量数据，则应将其设置为高一点）*/
#define MEMP_NUM_PBUF              50

/* MEMP_NUM_UDP_PCB: UDP控制块的数量
 */
#define MEMP_NUM_UDP_PCB          6

/* MEMP_NUM_TCP_PCB: TCP控制块的数量
 */
#define MEMP_NUM_TCP_PCB          10

/* MEMP_NUM_TCP_PCB_LISTEN： 侦听TCP连接的数量
 */
#define MEMP_NUM_TCP_PCB_LISTEN 6

/* MEMP_NUM_TCP_SEG： 同时排队的TCP块的数量
 */
#define MEMP_NUM_TCP_SEG          12

/* MEMP_NUM_SYS_TIMEOUT： 同时活动的超时数
 */
#define MEMP_NUM_SYS_TIMEOUT     10

/* ---------- pbuf配置 ---------- */
/* PBUF_POOL_SIZE: pbuf池中的缓冲区数量 */
#define PBUF_POOL_SIZE             10                                                 //(4)

/* PBUF_POOL_BUFSIZE: pbuf池中每个pbuf的大小 */
#define PBUF_POOL_BUFSIZE         500                                                 //(5)

/* ---------- TCP配置 ---------- */
#define LWIP_TCP                    1
#define TCP_TTL                      255

/* 控制TCP是否应对无序到达的段进行排队。如果设备内存不足，请定义为0 */
#define TCP_QUEUE_OOSEQ            0

/* TCP最大报文段大小 */
#define TCP_MSS                      (1500-40)                                      //(6)

/* TCP发送方缓冲区空间（字节）*/
#define TCP_SND_BUF                 (4*TCP_MSS)                                     //(7)

/* TCP_SND_QUEUELEN: TCP发送方缓冲区空间（pbufs）*/
#define TCP_SND_QUEUELEN          (2* TCP_SND_BUF/TCP_MSS)

/* TCP接收窗口 */
#define TCP_WND                      (2*TCP_MSS)                                   //(8)

/* ---------- ICMP设置 ---------- */
#define LWIP_ICMP                             1

/* ---------- DHCP设置 ---------- */
/* 如果要使用网卡的DHCP配置，请将LwIP_DHCP定义为1 */
#define LWIP_DHCP                   1


/* ---------- UDP配置 ---------- */
#define LWIP_UDP                    1
#define UDP_TTL                      255

/* ---------- 统计配置 ---------- */
#define LWIP_STATS 0
#define LWIP_PROVIDE_ERRNO 1

/* ---------- 链接回调配置 ---------- */
/* LWIP_NETIF_LINK_CALLBACK==1： 支持来自接口的回调函数
 */
#define LWIP_NETIF_LINK_CALLBACK          0


/*
    --------------------------------------
    ---------- 校验和配置 ----------
    --------------------------------------
*/

/* STM32F4x7 允许通过硬件计算和验证IP、UDP、TCP和ICMP校验和：
 * 通过宏定义CHECK_BY_HARDWARE选择是否需要硬件校验和 */

#define CHECKSUM_BY_HARDWARE

#ifdef CHECKSUM_BY_HARDWARE
/* CHECKSUM_GEN_IP==0： 通过硬件为传出的IP数据报生成校验和 */
#define CHECKSUM_GEN_IP                     0
/* CHECKSUM_GEN_UDP==0： 通过硬件为传出的UDP数据包生成校验和 */
#define CHECKSUM_GEN_UDP                    0
/* CHECKSUM_GEN_TCP==0： 通过硬件为传出的TCP数据包生成校验和 */
#define CHECKSUM_GEN_TCP                    0
/* CHECKSUM_CHECK_IP==0： 检查传入IP数据报的硬件校验和 */
#define CHECKSUM_CHECK_IP                   0
/* CHECKSUM_CHECK_UDP==0： 检查传入UDP数据包的硬件校验和 */
#define CHECKSUM_CHECK_UDP                  0
/* CHECKSUM_CHECK_TCP==0： 检查传入TCP数据包的硬件校验和 */
#define CHECKSUM_CHECK_TCP                  0
/* CHECKSUM_CHECK_ICMP==0： 检查传入ICMP数据包的硬件校验和 */
#define CHECKSUM_GEN_ICMP                   0
#else
/* CHECKSUM_GEN_IP==1： 在软件中为传出的IP数据报生成校验和 */
#define CHECKSUM_GEN_IP                     1
/* CHECKSUM_GEN_UDP==1： 在软件中为传出的UDP数据包生成校验和 */
#define CHECKSUM_GEN_UDP                    1
/* CHECKSUM_GEN_TCP==1： 在软件中为传出的TCP数据包生成校验和 */
#define CHECKSUM_GEN_TCP                    1
/* CHECKSUM_CHECK_IP==1： 检查软件中的校验和是否有传入的IP数据报 */
#define CHECKSUM_CHECK_IP                   1
/* CHECKSUM_CHECK_UDP==1： 检查软件中的校验和是否有传入的UDP数据包 */
#define CHECKSUM_CHECK_UDP                  1
/* CHECKSUM_CHECK_TCP==1： 检查软件中的校验和是否有传入的TCP数据包 */
#define CHECKSUM_CHECK_TCP                  1
/* CHECKSUM_CHECK_ICMP==1： 检查传入ICMP数据包的硬件校验和 */
#define CHECKSUM_GEN_ICMP                   1
#endif


/*
    ----------------------------------------------
    ---------- Netconn API配置 ----------
    ----------------------------------------------
*/
/*
 * LWIP_NETCONN==1： 启用Netconn API（需要使用api_lib.c）
 */
#define LWIP_NETCONN                          0                                        //(9)

/*
    ------------------------------------
    ---------- Socket API配置 ----------
    ------------------------------------
*/
/*
 * LWIP_SOCKET==1： 启用Socket API（需要使用sockets.c）
 */
#define LWIP_SOCKET                           0                                       //(10)


/*
    ----------------------------------------
    ---------- LwIP调试配置 ----------
    ----------------------------------------
*/
//#define LWIP_DEBUG                          1

#endif /* __LWIPOPTS_H__ */

 /*********************************************(C) COPYRIGHT STMicroelectronics *********END OF FILE****/
 