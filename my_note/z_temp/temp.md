

vs code 主题
名称: Material Theme
ID: Equinusocio.vsc-material-theme
说明: The most epic theme now for Visual Studio Code
版本: 33.10.5
发布者: Equinusocio
VS Marketplace 链接: https://marketplace.visualstudio.com/items?itemName=Equinusocio.vsc-material-theme













/usr/include/mosquitto.h







Set the name of the calling thread, using the value in the location pointed to by (char *) arg2.  The name can be up to 16 bytes long, including the terminating null byte. (If the length of the string, including the terminating null byte, exceeds 16 bytes, the string is silently truncated.)  This is the same attribute that can be set via pthread_setname_np(3) and retrieved using pthread_getname_np(3).  The attribute is likewise accessible via /proc/self/task/tid/comm (see proc(5)), where tid is the thread ID of the calling thread, as returned by gettid(2).







Hi 卫军，跟随参数可调增加最低档 这个需求，APP是已经支持了吗，可以接受飞机端上报参数了吗？





Captain是在takeoff_task部分把command参数到转发给fc吧，task传数据到fc有参考吗







I|Signalman]:Report captain event(id: CAPTAIN_EVT_ID_CAMERA_STATUS cs_status { state: CAPTAIN_STOP_VIDEO })

D|CameraService]:CameraService Command Put. {4}

D|CameraService]:CameraService Command Done. {4}



enum *MediaCommandId* {

​    MEDIA_CMDID_SNAPSHOT,

​    MEDIA_CMDID_CONTINUOUS_SNAPSHOT_START,

​    MEDIA_CMDID_CONTINUOUS_SNAPSHOT_STOP,

​    MEDIA_CMDID_VIDEO_START,

​    MEDIA_CMDID_VIDEO_STOP,





ZZLOGD("CameraService Command Put. {%d}", *command*.id);







GES里面

\#include <FlightController/FlightController.hpp>

error: src/FlightController/FlightController.hpp: No such file or directory

这个文件不属于GES不属于Captain怎么包含进去呀



src/drone_platform/exception_manager/src/FlightController/FlightController.hpp













GES模块移植bug都改完了，编译通过了，需要测试一下功能吗？



/home/liubo/00-liubo/.wind/profiles/default.v10/terminal/user.sessions



home/liubo/00-liubo/.wind/profiles/default.v10/user.config



