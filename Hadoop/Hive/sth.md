Hive don't have **DUAL** table (empty table in Oracle), but can create it.
```sql
create table dual (dummy STRING)
insert into dual dummy("")
select now() from dual
```
