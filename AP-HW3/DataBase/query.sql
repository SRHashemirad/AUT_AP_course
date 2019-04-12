#1
select * 
from "User" where phone = '09120000001';

#2
update "User" 
	set email = 'apstudent2019@gmail.com',
 		updated_at = now()
	where phone = '09120000001';

#3
select title
from channel where id in
(select channel_id
from channel_membership where user_id in
(select id
from "User" where phone = '09120000001'));

#4
select count(id) from "User" where id in
(select user_id from channel_membership where channel_id in
(select id from channel where telegram_id = 'aut_ap_2019'));

#5
select email from "User" where phone like '0935%';

#6
select phone from "User" where id in
(select blocked_user_id from block_user where blocker_user_id in
(select id from	"User" where phone = '09120000001') and
 ecreated_at > (now() - interval '1 month'));

#7
select email from "User" where id in 
(select creator_id from channel where id in 
(select channel_id from channel_membership where user_id in 
(select id from "User" where email = 'apstudent2019@gmail.com')
and  channel_id in
 (select channel_id from
 (select channel_id, count(user_id) from channel_membership
 group by channel_id) as subq
  where count > 3)));

#8
select message_type, message_text from message where
(sender_id = (select id from "User" where telegram_id = 'amir.jahanshahi')
 and receiver_id = (select id from "User" where telegram_id ='sHDiV4RHs') or
(receiver_id = (select id from "User" where telegram_id = 'amir.jahanshahi')
 and sender_id = (select id from "User" where telegram_id ='sHDiV4RHs')))
order by created_at desc limit 10;

#9
select phone from "User" where id in 
(select creator_id from channel where id in
 (select channel_id from channel_message where
  updated_at in (select max from
  	(select max(updated_at) from
   channel_message group by channel_id) as subq
  where max < (now() - interval'1 month'))));