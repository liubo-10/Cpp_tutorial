//netif.h文件解读


#define LWIP_IPV4                       1
#define LWIP_NETIF_STATUS_CALLBACK      1
#define LWIP_NETIF_LINK_CALLBACK        1
#define LWIP_NETIF_REMOVE_CALLBACK      1
#define netif_get_client_data(netif, id)       (netif)->client_data[(id)]
#define LWIP_NETIF_HOSTNAME             1
#define LWIP_CHECKSUM_CTRL_PER_NETIF    1
#define MIB2_STATS                      1
#define LWIP_IGMP                       1
#define LWIP_NETIF_USE_HINTS            1
#define ENABLE_LOOPBACK                 1
#define LWIP_LOOPBACK_MAX_PBUFS         1



struct netif {

#if ! LWIP_SINGLE_NETIF
  /* 指向netif链表中的下一个 */
  struct netif *next;                                                               //(1)
#endif


#if LWIP_IPV4
  /* 网络字节中的IP地址、子网掩码、默认网关配置 */
  ip_addr_t ip_addr;
  ip_addr_t netmask;
  ip_addr_t gw;                                                                     //(2)
#endif /* LWIP_IPV4 */


  /* 此函数由网络设备驱动程序调用，将数据包传递到TCP/IP协议栈。
   * 对于以太网物理层，这通常是ethernet_input()*/
  netif_input_fn input;                                                             //(3)


#if LWIP_IPV4
  /* 此函数由IP层调用，在接口上发送数据包。通常这个功能，
   * 首先解析硬件地址，然后发送数据包。
   * 对于以太网物理层，这通常是etharp_output() */
  netif_output_fn output;                                                           //(4)
#endif /* LWIP_IPV4 */


  /* 此函数由ethernet_output()调用，当需要在网卡上发送一个数据包时，
   * 底层硬件输出数据函数，一般是调用自定义函数low_level_output */
  netif_linkoutput_fn linkoutput;                                                   //(5)


 #if LWIP_NETIF_STATUS_CALLBACK
  /* 当netif状态设置为up或down时调用此函数 */
  netif_status_callback_fn status_callback;                                         //(6)
#endif /* LWIP_NETIF_STATUS_CALLBACK */


 #if LWIP_NETIF_LINK_CALLBACK
      /* 当netif链接设置为up或down时，将调用此函数 */
      netif_status_callback_fn link_callback;                                       //(7)
#endif /* LWIP_NETIF_LINK_CALLBACK */



 #if LWIP_NETIF_REMOVE_CALLBACK
      /* 当netif被删除时调用此函数 */
      netif_status_callback_fn remove_callback;                                     //(8)
#endif /* LWIP_NETIF_REMOVE_CALLBACK */


  /* 此字段可由设备驱动程序设置并指向设备的状态信息，
   * 主要是将网卡的某些私有数据传递给上层，用户可以自由发挥，也可以不用 */
  void *state;                                                                     //(9)


#ifdef netif_get_client_data
  void* client_data[LWIP_NETIF_CLIENT_DATA_INDEX_MAX + LWIP_NUM_NETIF_CLIENT_DATA];
#endif


#if LWIP_NETIF_HOSTNAME
  /* netif的主机名，NULL也是一个有效值 */
  const char*   hostname;
#endif /* LWIP_NETIF_HOSTNAME */


#if LWIP_CHECKSUM_CTRL_PER_NETIF
      u16_t chksum_flags;
#endif /* LWIP_CHECKSUM_CTRL_PER_NETIF */


  /* 最大传输单位（以字节为单位），对于以太网一般设为 1500 */
  u16_t mtu;                                                                      //(10)
  
  /* 此网卡的链路层硬件地址 */
  u8_t hwaddr[NETIF_MAX_HWADDR_LEN];                                              //(11)
  
  /* 硬件地址长度，对于以太网就是MAC地址长度，为6字节 */
  u8_t hwaddr_len;                                                                //(12)
  
  /* 网卡状态信息标志位，是很重要的控制字段，
   * 它包括启用网卡功能、启用广播、启用ARP等重要控制位 */
  u8_t flags;                                                                     //(13)
  
  /* 字段用于保存每一个网卡的名字。用两个字符的名字来标识网络接
   * 口使用的设备驱动的种类，名字由设备驱动来设置并且应该反映通过网卡
   * 表示的硬件的种类。比如蓝牙（bluetooth）设备的网卡名字可以是bt，
   * 而IEEE 802.11b WLAN设备的名字就可以是wl，设置什么名字用户是可
   * 以自由发挥的，这并不影响用户对网卡的使用。当然，如果两个网卡
   * 具有相同的网络名字，我们就用num字段来区分相同类别的不同网卡 */
  char name[2];                                                                   //(14)
  
  /* 用来标识使用同种驱动类型的不同网卡 */
  u8_t num;                                                                       //(15)


#if MIB2_STATS
  /* 连接类型 */
  u8_t link_type;
  /* 连接速度 */
  u32_t link_speed;
  /* 最后一次更改的时间戳 */
  u32_t ts;
  /* counters */
  struct stats_mib2_netif_ctrs mib2_counters;
#endif /* MIB2_STATS */


#if LWIP_IPV4 && LWIP_IGMP
  /* 这是以太网MAC的过滤表函数，可
   * 以调用此函数来添加或删除多播包 */
  netif_igmp_mac_filter_fn igmp_mac_filter;
#endif /* LWIP_IPV4 && LWIP_IGMP */


#if LWIP_NETIF_USE_HINTS
      struct netif_hint *hints;
#endif /* LWIP_NETIF_USE_HINTS */


#if ENABLE_LOOPBACK
  /* 环回列表指针 */
  struct pbuf *loop_first;
  struct pbuf *loop_last;

#if LWIP_LOOPBACK_MAX_PBUFS
  u16_t loop_cnt_current;
#endif /* LWIP_LOOPBACK_MAX_PBUFS */

#endif /* ENABLE_LOOPBACK */

};

