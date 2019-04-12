CREATE TABLE "User" (
	id SERIAL PRIMARY KEY,
	telegram_id VARCHAR(255) NOT NULL,
	phone VARCHAR(11) NOT NULL,
	email VARCHAR(255) NOT NULL,
	password VARCHAR(255) NOT NULL,
	first_name VARCHAR(30) NOT NULL,
	last_name VARCHAR(30) NOT NULL,
	verification_code VARCHAR(10) NOT NULL,
	profile_picture_url TEXT NOT NULL,
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL
);

create table block_user (
	blocker_user_id integer not null,
	blocked_user_id integer not null,
	ecreated_at timestamp not null,
	primary key (blocker_user_id, blocked_user_id),
	foreign key (blocked_user_id) references "User"(id),
	foreign key (blocker_user_id) references "User"(id)
);

create type message_struct as enum (
	'audio',
	'video',
	'image',
	'text'
);

create table message (
	id serial primary key,
	sender_id integer not null,
	receiver_id integer not null,
	message_type message_struct not null,
	message_text text not null,
	created_at timestamp no
	telegram_id varchar(255) not null,
	title varchar(30) not null,
	info varchar(100),
	creator_id integer not null,
	created_at timestamp not null,
	updated_at timestamp not null,
	foreign key (creator_id) references "User"(id)
);

create table "Group" (
	id serial primary key,
	creator_id integer not null,
	title varchar(30) not null,
	join_url text not null,
	created_at timestamp not null,
	updated_at timestamp not null,
	foreign key (creator_id) references "User"(id)
);

create table group_message (
	id serial primary key,
	group_id integer not null,
	sender_id integer not null,
	message_type message_struct not null,
	message_text text not null,
	created_at timestamp not null,
	updated_at timestamp not null,
	foreign key (group_id) references "Group"(id),
	foreign key (sender_id) references "User"(id)
);

create table channel_message (
	id serial primary key,
	channel_id integer not null,
	message_type message_struct not null,
	message_text text not null,
	created_at timestamp not null,
	updated_at timestamp not null,
	foreign key (channel_id) references channel (id)
);

create table message_attachment (
	message_id integer not null,
	attachment_url text not null,
	attachment_thumb_url text not null,
	primary key (message_id, attachment_url, attachment_thumb_url),
	foreign key (message_id) references message (id)
);

create table group_message_attachment (
	message_id integer not null,
	attachment_url text not null,
	attachment_thumb_url text not null,
	primary key (message_id, attachment_url, attachment_thumb_url),
	foreign key (message_id) references group_message(id)
);

create table channel_message_attachment (
	message_id integer not null,
	attachment_url text not null,
	attachment_thumb_url text not null,
	primary key (message_id, attachment_url,
	 attachment_thumb_url),
	foreign key (message_id) references channel_message (id)
);

create table channel_membership(
	user_id integer not null,
	channel_id integer not null,
	created_at timestamp not null,
	primary key (user_id, channel_id),
	foreign key (user_id) references "User"(id),
	foreign key (channel_id) references channel (id)
);

create table group_membership (
	user_id integer not null,
	group_id integer not null,
	primary key (user_id, group_id),
	created_at timestamp not null,
	foreign key (user_id) references "User"(id),
	foreign key (group_id) references "Group"(id)
);