void check_owner();
void destroy(object ob);

void init()
{
        check_owner();
}


void check_owner()
{
        object ob =this_object();
        object me =environment(ob);
if ( !me->query("gongs/all"))
       call_out("destroy", 0, ob, me);                       
//           destroy(ob);
}
void destroy(object ob)
{
        write(ob->query("name")+"呼的不见了！ \n");
        destruct(ob);
        return;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
