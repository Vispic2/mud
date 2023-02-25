// chinese name hh
// 更新的内容：
// mapping get_cn_name() - 返回一套随机姓名 & ID

#include "name.h"

mapping get_cn_name();

mapping cn_sname = ([
        "阿" : "a",
        "艾" : "ai",
        "爱" : "ai",
        "敖" : "ao",
        "白" : "bai",
        "鲍" : "bao",
        "毕" : "bi",
        "卞" : "bian",
        "蔡" : "cai",
        "曹" : "cao",
        "陈" : "chen",
        "楚" : "chu",
        "戴" : "dai",
        "窦" : "dou",
        "邓" : "deng",
        "狄" : "di",
        "杜" : "du",
        "段" : "duan",
        "范" : "fan",
        "樊" : "fan",
        "房" : "fang",
        "冯" : "feng",
        "符" : "fu",
        "福" : "fu",
        "高" : "gao",
        "古" : "gu",
        "关" : "guan",
        "郭" : "guo",
        "韩" : "han",
        "胡" : "hu",
        "花" : "hua",
        "洪" : "hong",
        "侯" : "hou",
        "黄" : "huang",
        "季" : "ji",
        "贾" : "jia",
        "江" : "jiang",
        "蒋" : "jiang",
        "金" : "jin",
        "柯" : "ke",
        "孔" : "kong",
        "寇" : "kou",
        "匡" : "kuang",
        "廖" : "liao",
        "梁" : "liang",
        "李" : "li",
        "林" : "lin",
        "刘" : "liu",
        "龙" : "long",
        "陆" : "lu",
        "卢" : "lu",
        "罗" : "luo",
        "马" : "ma",
        "毛" : "mao",
        "梅" : "mei",
        "苗" : "miao",
        "年" : "nian",
        "聂" : "nie",
        "宁" : "ning",
        "牛" : "niu",
        "潘" : "pan",
        "庞" : "pang",
        "裴" : "pei",
        "彭" : "peng",
        "戚" : "qi",
        "齐" : "qi",
        "钱" : "qian",
        "乔" : "qiao",
        "秦" : "qin",
        "邱" : "qiu",
        "裘" : "qiu",
        "仇" : "qiu",
        "冉" : "ran",
        "任" : "ren",
        "阮" : "ruan",
        "沙" : "sha",
        "商" : "shang",
        "尚" : "shang",
        "邵" : "shao",
        "沈" : "shen",
        "师" : "shi",
        "施" : "shi",
        "宋" : "song",
        "孙" : "sun",
        "唐" : "tang",
        "陶" : "tao",
        "田" : "tian",
        "童" : "tong",
        "万" : "wan",
        "王" : "wang",
        "魏" : "wei",
        "卫" : "wei",
        "吴" : "wu",
        "武" : "wu",
        "习" : "xi",
        "萧" : "xiao",
        "肖" : "xiao",
        "项" : "xiang",
        "许" : "xu",
        "徐" : "xu",
        "薛" : "xue",
        "杨" : "yang",
        "羊" : "yang",
        "阳" : "yang",
        "易" : "yi",
        "尹" : "yin",
        "俞" : "yu",
        "赵" : "zhao",
        "钟" : "zhong",
        "周" : "zhou",
        "郑" : "zheng",
        "朱" : "zhu",

        "东方" : "dongfang",
        "独孤" : "dugu",
        "慕容" : "murong",
        "欧阳" : "ouyang",
        "司马" : "sima",
        "西门" : "ximen",
        "尉迟" : "yuchi",
        "长孙" : "zhangsun",
        "诸葛" : "zhuge",
        "上官" : "shangguan",
        "夏侯" : "xiahou",
        "闻人" : "wenren",
        "皇甫" : "huangfu",
        "澹台" : "tantai",
        "公治" : "gongzhi",
        "淳于" : "chunyu",
        "申屠" : "shentu",
        "公孙" : "gongsun",
        "公羊" : "gongyang",
        "轩辕" : "xuanyuan",
        "令狐" : "linghu",
        "钟离" : "zhongli",
        "宇文" : "yuwen",
        "慕容" : "murong",
        "仲孙" : "zhongsun",
        "司徒" : "situ",
        "司空" : "sikong",
        "端木" : "duanmu",
        "公良" : "gongliang",
        "百里" : "baili",
        "东郭" : "dongguo",
        "鲜于" : "xianyu",
        "南郭" : "nanguo",
        "呼延" : "huyan",
        "羊舌" : "yangshe",
        "东门" : "dongmen",
        "纳兰" : "nalan",
        "南官" : "nanguan",
        "南宫" : "nangong",
        "拓拔" : "tuoba",
        "完颜" : "wanyan",
        "耶律" : "yelv",
]);
//男性NPC名字
mapping cn_pname1 = ([
        "ai"   : "皑哀蔼隘埃瑷嫒捱",
        "an"   : "安黯谙岸鞍埯鹌",
        "ao"   : "奥傲敖骜翱鳌",
        "ang"  : "昂盎肮",
        "ba"   : "罢霸跋魃",
        "bai"  : "白佰",
        "ban"  : "斑般",
        "bang" : "邦",
        "bei"  : "北倍贝备",
        "biao" : "表标彪飚飙",
        "bian" : "边卞弁忭",
        "bu"   : "步不",
        "cao"  : "曹草操漕",
        "cang" : "苍仓",
        "chang": "常长昌敞玚",
        "chi"  : "迟持池赤尺驰炽",
        "ci"   : "此次词茨辞慈",
        "du"   : "独都",
        "dong" : "东侗",
        "dou"  : "都篼",
        "fa"   : "发乏珐",
        "fan"  : "范凡反泛帆蕃",
        "fang" : "方访邡昉",
        "feng" : "风封丰奉枫峰锋",
        "fu"   : "夫符弗芙",
        "gao"  : "高皋郜镐",
        "hong" : "洪红宏鸿虹泓弘",
        "hu"   : "虎忽湖护乎祜浒怙",
        "hua"  : "化华骅桦",
        "hao"  : "号浩皓蒿浩昊灏淏",
        "ji"   : "积极济技击疾及基集记纪季继吉计冀祭际籍绩忌寂霁稷玑芨"
                 "蓟戢佶奇诘笈畿犄",
        "jian" : "渐剑见建间柬坚俭",
        "kan"  : "刊戡龛",
        "ke"   : "可克科刻珂恪溘牁",
        "lang" : "朗浪廊琅阆莨",
        "li"   : "历离里理利立力丽礼黎栗荔沥栎璃",
        "lin"  : "临霖林",
        "ma"   : "马犸",
        "mao"  : "贸冒貌冒懋矛卯瑁",
        "miao" : "淼渺邈",
        "nan"  : "楠南腩赧",
        "pian" : "片翩胼",
        "qian" : "潜谦乾虔千",
        "qiang": "强羌锖玱",
        "qin"  : "亲钦沁芩矜",
        "qing" : "清庆卿晴",
        "ran"  : "冉然染燃",
        "ren"  : "仁刃壬仞",
        "sha"  : "沙煞",
        "shang": "上裳商",
        "shen" : "深审神申慎参莘",
        "shi"  : "师史石时十世士诗始示适炻",
        "shui" : "水",
        "si"   : "思斯丝司祀嗣巳",
        "song" : "松颂诵",
        "tang" : "堂唐棠瑭",
        "tong" : "统通同童彤仝",
        "tian" : "天田忝",
        "wan"  : "万宛晚",
        "wei"  : "卫微伟维威韦纬炜惟玮为",
        "wu"   : "吴物务武午五巫邬兀毋戊",
        "xi"   : "西席锡洗夕兮熹惜",
        "xiao" : "潇萧笑晓肖霄骁校",
        "xiong": "熊雄",
        "yang" : "羊洋阳漾央秧炀飏鸯",
        "yi"   : "易意依亦伊夷倚毅义宜仪艺译翼逸忆熠沂颐奕弈懿翊轶屹猗翌",
        "yin"  : "隐因引银音寅吟胤訚荫",
        "ying" : "映英影应郢鹰",
        "you"  : "幽悠右忧猷酉",
        "yu"   : "渔郁寓于余预羽舆育宇禹域誉瑜屿御渝毓虞禺豫裕钰煜聿",
        "zhi"  : "制至值知质致智志直治执止置芝旨峙芷挚郅炙雉帜",
        "zhong": "中忠钟衷",
        "zhou" : "周州舟胄繇昼",
        "zhu"  : "竹主驻朱祝诸著竺",
        "zhuo" : "卓灼灼拙琢濯斫擢焯酌",
        "zi"   : "子资兹孜梓",
        "zong" : "宗枞",
        "zu"   : "足族祖卒",
        "zuo"  : "作左佐笮凿",
]);

//女性NPC名字
mapping cn_pname2 = ([
        "ai"   : "嫒爱",
        "bei"  : "蓓贝",
        "bi"   : "碧",
        "fang" : "芳",
        "feng" : "凤",
        "hong" : "红虹",
        "hua"  : "花华",
        "hui"  : "惠慧彗荟",
        "ji"   : "姬",
        "jia"  : "佳嘉",
        "jiao" : "姣娇",
        "jie"  : "洁婕",
        "jing" : "静晶婧",
        "li"   : "丽黎莉俪麗",
        "lian" : "恋莲",
        "lin"  : "魿琳",
        "lu"   : "露璐",
        "man"  : "曼漫嫚",
        "mei"  : "美梅媚莓",
        "meng" : "梦萌",
        "miao" : "苗淼妙",
        "qi"   : "琪婍",
        "qian" : "倩茜纤",
        "qin"  : "亲琴沁芩芹",
        "qing" : "清晴青箐",
        "sha"  : "莎",
        "si"   : "思姒",
        "tong" : "彤",
        "tian" : "甜",
        "ting" : "婷",
        "wan"  : "婉莞菀妧娩婠",
        "wei"  : "薇",
        "xi"   : "夕曦",
        "xiao" : "潇晓",
        "xiang": "香湘襄",
        "xue"  : "雪",
        "ya"   : "雅娅亚",
        "yan"  : "烟燕艳颜妍嫣",
        "yang" : "洋漾鸯婸姎",
        "yao"  : "姚媱瑶窈",
        "yi"   : "依伊宜仪艺怡奕懿",
        "yin"  : "音吟荫茵",
        "ying" : "英颖瑛莹盈樱莺",
        "yu"   : "郁玉雨语羽瑜妤",
        "zhen" : "珍贞",
        "zhi"  : "芝芷雉脂稚",
        "zhu"  : "珠茱",
        "zi"   : "紫姿秭",
]);

void generate_cn_name(object ob)
{
	mapping ret;

	if (! ob) return;

	ret = get_cn_name();
	
	ob->set_name(ret["name"], ret["id"]);
}
mapping get_cn_name()
{
        string sname, pname, pname2, id1, id2;
        string *ks, *kp;
        mapping cn_pname;
        if(random(2))
        cn_pname=cn_pname2;
        else
        cn_pname=cn_pname1;
        ks = keys(cn_sname);
        kp = keys(cn_pname);
        sname = ks[random(sizeof(ks))];
        for (;;)
        {
                pname = kp[random(sizeof(kp))];
                if (pname != cn_sname[sname]) break;
        }
        id1 = cn_sname[sname];

        id2 = pname;
        pname = cn_pname[pname];
        pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1];
        pname = pname[0..0];
        if (random(3) == 0)
        {
                for (;;)
                {
                        pname2 = kp[random(sizeof(kp))];
                        if (pname2 != cn_sname[sname] &&
                            pname2 != pname) break;
                }
                id2 += pname2;
                pname2 = cn_pname[pname2];
                pname2 = pname2[(random(sizeof(pname2)) & 0xFFFE)..<1];
                pname2 = pname2[0..0];
        } else
                pname2 = "";

             return ([ "name" : sname + pname + pname2,"id"   : ({ id1 + " " + id2, id1, id2, }), ]);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
