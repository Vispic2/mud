#include <getconfig.h>
//#define NOR ""
#define ZJKEY           "123456789abcd" 
#define NAME_PAY		"124.223.83.184"  //充值网站
#define ZJIP "124.223.83.184"  //服务器IP
#define KFPORT 5005  //跨服聊天端口 (发送给对面服务器的)
#define JTKFPORT 5006 //本服跨服聊天监听端口



/*
#define ESA		    "" 
#define ZJSEP		"$zj#"
#define ZJSP2		"$z2#"
#define XJSP1		"$x1#"
#define ZJBR		"$br#"
#define ZJURL(w)	ESA + "[u:" + w + "]"
#define ZJSIZE(n)	ESA + "[s:" + n + "]"
#define DMZDYYS(w)	ESC + "#zdy$" + w + "m"//自定义颜色

#define SYSY		ESA + "000"
#define INPUTTXT(a,b)	ESA + "001" + a + ZJSEP + b
#define XYMRX		ESA + "10a"//跑马灯展示(弃用)
#define XYMRU		ESA + "11a"//好友提示
#define XYLIE		ESA + "211"
#define XYLIF		ESA + "212"
#define XYLIG		ESA + "213"
#define XYLIK		ESA + "214"
#define XYLIL		ESA + "215"
#define DMLJ		ESA + "999"//改变socket连接
#define XYKILL		ESA + "511"//战斗添加敌人
#define XYKILLD		ESA + "512"//战斗添加队友
#define XYKILLDY		ESA + "513"//战斗减少敌人
#define XYKILLDT	ESA + "514"//战斗减少队友
#define XYKILLMIAO	ESA + "515"//战斗描述
#define KILLEND	    ESA + "516"//战斗结束
#define KILLJN    ESA + "517"//战斗技能
#define KILLKS    ESA + "518"//战斗开始
#define KILLQL   ESA + "519"//清理战场
#define XJTILI   ESA + "521"//体力
#define XYJI		ESA + "217"
#define XYRWNAME		ESA + "417"//人物名称
#define XYRWMIAO		ESA + "418"//人物描述
#define XYRWBUT1		ESA + "419"//人物按钮1
#define XYRWBUT2		ESA + "420"//人物按钮2
#define XYRWBUT3		ESA + "421"//人物描述
#define XYSHOPJZ	ESA + "343"//元宝数量
#define XYSHOPLX	ESA + "344"//商城类型
#define XYSHOP		ESA + "345"//商场物品
#define XYBBTEXT		ESA + "346"//背包文本
#define XYBEIBAO		ESA + "347"//背包物品
#define XYCWD		ESA + "348"//储物袋物品
#define XYCWDT		ESA + "349"//储物袋文本
#define XYBEIBAOT	ESA + "350"//背包文本2
#define XYZFUBEN	ESA + "270"//副本
#define XYZFBTE	    ESA + "271"//副本文本
#define XYZFBLIE	ESA + "272"//副本列表
#define XYZZHSXBT	ESA + "291"//综合属性标题
#define XYZZHSXXX	ESA + "292"//综合属性选项
#define XYZZHSXWB	ESA + "293"//综合属性文本
#define XYZZHSXWB1	ESA + "296"//综合属性文本1
#define XYZZHSXWB2	ESA + "297"//综合属性文本2
#define XJYS1	ESA + "2k1"//综合属性样式一
#define XJYS2	ESA + "2k2"//综合属性样式二
#define XJYS3	ESA + "2k3"//综合属性样式三
#define XJYS4	ESA + "2k4"//综合属性样式四
#define DMJHLOOK	ESA + "111"//查看自身
#define DMJHPAI	ESA + "331"//排行榜标题
#define DMJHPAILEI	ESA + "332"//排行榜类型
#define DMJHPAIMING	ESA + "333"//排行榜名次
#define XYZZHSXBUT(r)	ESA + "294"+r//综合属性按钮
#define XYZZHSXBUT1(r)	ESA + "295"+r//综合属性按钮
#define XYSHAN	    "#s$"//闪烁效果1紫
#define XYSHAN1	    "#d$"//闪烁效果2红
#define DMZHUYET	ESA + "602"//主页文本1
#define DMZHUYETY	ESA + "603"//主页文本2
#define DMZHUJMQH	ESA + "604"//判断界面
#define DMZHUJIU	ESA + "605"//更改界面
#define XCGX       	ESA + "701"//每日贡献
#define XYFRIENDS1       	ESA + "491"//好友按钮1
#define XYFRIENDS2      	ESA + "492"//好友按钮2
#define XYFRIENDS3      	ESA + "493"//好友按钮3
#define XYFRIENDS4      	ESA + "494"//好友按钮4
#define XYFRIENDS5      	ESA + "495"//聊天信息
#define XYFRIENDS6      	ESA + "496"//启动聊天
#define XYFRIENDS7      	ESA + "497"//聊天信息
#define XYFRIENDS8      	ESA + "498"//聊天信息
#define JHYJMP       	ESA + "702"//门派
#define JHYJMP1       	ESA + "703"//门派类型
#define DMTEXTTQP(w)	ESA + "[&"+w+"]m"//文字图片
#define ZJTITLE		ESA + "002"
#define ZJEXIT		ESA + "003"
#define ZJEXIT1		ESA + "030"//地图处理
#define ZJEXITRM	ESA + "903"
#define ZJEXITCL	ESA + "913"
#define ZJLONG		ESA + "004"
#define ZJOBIN		ESA + "005"
#define ZJOBOUT		ESA + "905"
#define ZJBTSET		ESA + "006"
#define ZJOBLONG	ESA + "007"
#define ZJOBACTS	ESA + "008"
#define ZJOBACTS2	ESA + "009"
#define ZJYESNO		ESA + "010"
#define ZJMAPTXT	ESA + "011"
#define DMMAP    	ESA + "286"//查看地图
#define XYTEXT	    ESA + "311"
#define XYTEXT1	    ESA + "310"//物品标题
#define XYTEXT2	    ESA + "309"//物品描述
#define XYTEXT3	    ESA + "308"//物品按钮
#define XYTISHI	    ESA + "130"//提示信息，文本上升动画
#define YJBUTTON	    ESA + "450"//按键
#define ZJHPTXT		ESA + "012"
#define ZJHPTXT1		ESA + "234"
#define ZJMORETXT	ESA + "013"
#define ZJFORCECMD(c)	ESA + "014" + c + "\n"
#define ZJTMPSAY	ESA + "015"
#define ZJFMSG		ESA + "016"
#define ZJFNOMSG	ESA + "017"

#define ZJPOPMENU	ESA + "020"
#define ZJMENUF(r,w,h,s)	"$"+r+","+w+","+h+","+s+"#"
#define ZJTTMENU	ESA + "021"
#define ZJCHARHP	ESA + "022"
#define ZJLONGXX	ESA + "023"

#define ZJCHANNEL	ESA + "100"
#define SYSEXIT		ESA + "999"
*/
//ָ��MUDת��Э��

//#define ZJKEY		"123456789abcd"
//#define ZJPAYPORT		3041
//#define ZJUDPPORT		3044

#define ESA		"" 
#define ZJSEP		"$zj#"
#define ZJSP2		"$z2#"
#define ZJBR		"$br#"
#define ZJURL(w)	ESA + "[u:" + w + "]"
#define ZJSIZE(n)	ESA + "[s:" + n + "]"

#define SYSY		ESA + "000"
#define INPUTTXT(a,b)	ESA + "001" + a + ZJSEP + b
#define ZJTITLE		ESA + "002"
#define ZJEXIT		ESA + "003"
#define ZJEXITRM	ESA + "903"
#define ZJEXITCL	ESA + "913"
#define ZJLONG		ESA + "004"
#define ZJOBIN		ESA + "005"
#define ZJOBOUT		ESA + "905"
#define ZJBTSET		ESA + "006"
#define ZJOBLONG	ESA + "007"
#define ZJOBACTS	ESA + "008"
#define ZJOBACTS2	ESA + "009"
#define ZJYESNO		ESA + "010"
#define ZJMAPTXT	ESA + "011"
#define ZJHPTXT		ESA + "012"
#define ZJMORETXT	ESA + "013"
#define ZJFORCECMD(c)	ESA + "014" + c + "\n"
#define ZJTMPSAY	ESA + "015"
#define ZJFMSG		ESA + "016"
#define ZJFNOMSG	ESA + "017"

#define ZJPOPMENU	ESA + "020"
#define ZJMENUF(r,w,h,s)	"$"+r+","+w+","+h+","+s+"#"
#define ZJTTMENU	ESA + "021"
#define ZJCHARHP	ESA + "022"
#define ZJLONGXX	ESA + "023"

#define ZJCHANNEL	ESA + "100"
#define SYSEXIT		ESA + "999"

