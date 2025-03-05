#!/bin/bash





eval $(ssh-agent -s)
ssh-add /home/liubo/00-liubo/my_material/my_note/git/git_key/gitlab_rsa 

eval $(ssh-agent -s)
ssh-add /home/liubo/00-liubo/my_material/my_note/git/git_key/github_rsa




echo 清理本地不存在的远程分支，如别人删除了dev,但是你本地查看还有，就可以执行该条命令
git remote prune origin

echo 更新远程分支列表
git remote update origin --prune









#  使用read命令达到类似bat中的pause命令效果
echo 按任意键继续
read -n 1
echo 继续运行

