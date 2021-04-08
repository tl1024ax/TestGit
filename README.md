# TestGit
这个是测试 Git 的功能的项目
https://github.com/tl1024ax/TestGit

Get started by creating a new file or uploading an existing file. 
We recommend every repository include a README, LICENSE, and .gitignore.

---------------------------
…or create a new repository on the command line
------
echo "# TestGit" >> README.md

git init

git add README.md

git commit -m "first commit"

git branch -M main

git remote add origin git@github.com:tl1024ax/TestGit.git

git push -u origin main

---------------------------
解决冲突

链接：https://www.jianshu.com/p/920ad324fe64https://www.jianshu.com/p/920ad324fe64
------
git stash
git pull
git stash pop

命令介绍
------
git stash: 备份当前的工作区的内容，从最近的一次提交中读取相关内容，让工作区保证和上次提交的内容一致。
	同时，将当前的工作区内容保存到Git栈中。

git pull:拉取服务器上的代码；

git stash pop: 从Git栈中读取最近一次保存的内容，恢复工作区的相关内容。
	由于可能存在多个Stash的内容，所以用栈来管理，pop会从最近的一个stash中读取内容并恢复。

git stash list: 显示Git栈内的所有备份，可以利用这个列表来决定从那个地方恢复。

git stash clear: 清空Git栈。此时使用gitg等图形化工具会发现，原来stash的哪些节点都消失了。

---------------------------
…or push an existing repository from the command line
------
git remote add origin git@github.com:tl1024ax/TestGit.git

git branch -M main

git push -u origin main

---------------------------
…or import code from another repository
------

You can initialize this repository with code from a Subversion, Mercurial, or TFS project.
