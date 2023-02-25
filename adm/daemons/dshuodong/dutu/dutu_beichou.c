inherit F_DBASE;
#define CITY_DIR "/d/foshan/"
#define DUTU_COUNT 15

int strat_dutu();
object * get_room();
void create_and_move_npc(object * room);

object * npc = ({});

int start()
{
    object * room;
    
    if(!sizeof(npc))
        npc = ({});
    
    if (!arrayp(room = get_room()) && !sizeof(room))
        return 0;
    else
        create_and_move_npc(room);
    
    message("channel:chat", "【赌场】好你个糟老头子，没钱还敢来赌钱！！！！\n", users());
    QQ_D->msg("【赌场】好你个糟老头子，没钱还敢来赌钱！！！！");
    call_out("remove_npc", 1800);
    //log_files("dutu_beichou", ctime(time()) + "赌徒活动开启。\n");
    return 1;
}

object * get_room()
{
    string * room_file;
    int i;
    object * room = ({});
    
    room_file = list_dirs(CITY_DIR);
    for(i = 0; i < sizeof(room_file); i++)
    {
        room_file[i] = CITY_DIR + room_file[i];
        room += ({load_object(room_file[i])});
    }
    
    return room;
}

void create_and_move_npc(object * room)
{
    int i;
    object beichou, dutu, beichou_room;
    
    beichou = new(__DIR__"beichou");
    npc += ({beichou});
    beichou->move(room[random(sizeof(room))]);
    
    for(i = 0; i < DUTU_COUNT; i++)
    {
        dutu = new(__DIR__"dutu");
        npc += ({dutu});
        dutu->move(room[random(sizeof(room))]);
    }
}

void remove_npc()
{
    int i;
    
    for(i = 0; i < DUTU_COUNT + 1; i++)
    {
        if (objectp(npc[i]))
            destruct(npc[i]);
    }
    
    npc = ({});
}

void beichou_die()
{
    int i;
    
    remove_call_out("remove_npc");
    for(i = 0; i < DUTU_COUNT + 1; i++)
    {
        if (objectp(npc[i]) && npc[i]->is_dutu())
            destruct(npc[i]);
    }
    
    npc = ({});
}

void print_npc()
{
 //   tell_object(find_player("qianmu"), sprintf("测试节点%O\n", npc));
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
