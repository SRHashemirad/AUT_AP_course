insert into "User" values (default, 'id001', '09120000001',
 'email001@gmail.com', md5('12345'), 'first001', 'last001',
  '12345', 'http://pic001', now(), now());

insert into "User" values (default, 'id002', '09120000002',
 'email002@gmail.com', md5('12345'), 'first002', 'last002',
  '12345', 'http://pic002', now(), now());

insert into "User" values (default, 'id003', '09120000003',
 'email003@gmail.com', md5('12345'), 'first003', 'last003',
  '12345', 'http://pic003', now(), now());

insert into "User" values (default, 'id004', '09120000004',
 'email004@gmail.com', md5('12345'), 'first004', 'last004',
  '12345', 'http://pic004', now(), now());

insert into "User" values (default, 'id005', '09120000005',
 'email005@gmail.com', md5('12345'), 'first005', 'last005',
  '12345', 'http://pic005', now(), now());

insert into "User" values (default, 'id006', '09350000006',
 'email006@gmail.com', md5('12345'), 'first006', 'last006',
  '12345', 'http://pic006', now(), now());

insert into "User" values (default, 'sHDiV4RHs', '09350000007',
 'email007@gmail.com', md5('12345'), 'first007', 'last007',
  '12345', 'http://pic007', now(), now());

insert into "User" values (default, 'amir.jahanshahi', '09350000008',
 'email008@gmail.com', md5('12345'), 'first008', 'last008',
  '12345', 'http://pic008', now(), now());

insert into channel values (default, 'chid001', 'title1',
 'noinfo', 2, now(), now());

insert into channel values (default, 'chid002', 'title2',
 'noifnfo', 3, now(), now());

insert into channel_membership values (1, 1, now());

insert into channel_membership values (1, 2, now());

insert into channel values (default, 'aut_ap_2019', 'ap_2019',
 'noinfo', 2, now(), now());

insert into channel_membership values (1, 3, now());
insert into channel_membership values (3, 3, now());
insert into channel_membership values (4, 3, now());
insert into channel_membership values (5, 3, now());

insert into block_user values (1, 2, now());
insert into block_user values (1, 5, now());
insert into block_user values (1, 6, now() - interval '2 month');

insert into message values (default, 9, 10, 'text', 
'message1', now(), now());
insert into message values (default, 10, 9, 'text', 
'message2', now(), now());
insert into message values (default, 9, 10, 'text', 
'message3', now(), now());
insert into message values (default, 10, 9, 'text', 
'message4', now(), now());
insert into message values (default, 9, 10, 'text', 
'message5', now(), now());
insert into message values (default, 10, 9, 'text', 
'message6', now(), now());
insert into message values (default, 9, 10, 'text', 
'message9', now(), now());
insert into message values (default, 9, 10, 'text', 
'message10', now(), now());
insert into message values (default, 9, 10, 'text', 
'message9', now(), now());
insert into message values (default, 10, 9, 'text', 
'message10', now(), now());
insert into message values (default, 10, 9, 'text', 
'message11', now(), now());


insert into channel_message values (default, 3, 'text',
 'message1', now(), now());
insert into channel_message values (default, 3, 'text',
 'message2', now() - interval '2 month', now() - interval '2 month');
insert into channel_message values (default, 1, 'text',
 'message3', now() - interval '2 month', now() - interval '2 month');
insert into channel_message values (default, 2, 'text',
 'message4', now(), now());
insert into channel_message values (default, 2, 'text',
 'message5', now(), now());
insert into channel_message values (default, 3, 'text',
 'message6', now(), now());