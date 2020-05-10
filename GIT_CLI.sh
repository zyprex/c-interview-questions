:'----------------------------------------
 this is my git command line interface
 everyone can feel free to use :)
 ----------------------------------------
 (Q)uit (C)lear (s)tatus (d)iff (l)og 
 (A)dd  (u)ndo
 (Co)mmit (U)ndo (R)edo
 (+P)ush
 (B)ranch (t)o (M)erge (D)elete (g)raph (st)ash
 ---------------------------------------- 
'
head -10 $0
# loop here
while true ; do
    echo -n ">>"
    read onekey
    if [[ $onekey == "Q" ]]; then
        break
    elif [[ $onekey == "C" ]]; then
        clear
        head -10 $0
    elif [[ $onekey == "s" ]]; then
        git status
    elif [[ $onekey == "d" ]]; then
        git diff --staged
    elif [[ $onekey == "l" ]]; then
        git log
    elif [[ $onekey == "A" ]]; then
        git add .
    elif [[ $onekey == "u" ]]; then
        echo -e "\033[4mgit reset HEAD^\033[0m"
        git reset HEAD^
        echo -e "TIPS: git checkout -- {yourfile}" 
    elif [[ $onekey == "Co" ]]; then
        echo -n "please give commit message: "
        read msg
        git commit -m"$msg"
    elif [[ $onekey == "U" ]]; then
        echo -e "\033[4mgit reset --hard HEAD^\033[0m"
        git reset --hard HEAD^
    elif [[ $onekey == "R" ]]; then
        echo -e "\033[4mgit reflog\033[0m"
        git reflog
        echo -n "commit id: "
        read dot
        git reset --hard $dot
    elif [[ $onekey == "+P" ]]; then
        git push origin master
    elif [[ $onekey == "B" ]]; then
        echo -n "new branch name: "
        read bname
        git branch $bname
    elif [[ $onekey == "t" ]]; then
        git branch
        echo -n "to branch: "
        read bname
        git checkout $bname
    elif [[ $onekey == "M" ]]; then
        git branch
        echo -n "merge branch to current branch: "
        read bname
        git merge $bname
    elif [[ $onekey == "D" ]]; then
        echo "use git branch -d {branch_name} delete branch"
    elif [[ $onekey == "g" ]]; then
        git log --graph
    elif [[ $onekey == "st" ]]; then
        echo "use (s)--stash (p)--stash pop (l)--list stash "
        read -n1 stashOps
        if [[ $stashOps == "s" ]]; then
            git stash
        elif [[ $onekey == "p" ]]; then
            git stash pop
        elif [[ $onekey == "l" ]]; then
            git stash list
        fi
    elif [[ $onekey =~ ^git.* ]]; then
        $onekey
    fi
done

:'----------------------------------------
              git guide
 ----------------------------------------
 git add 把文件添加到仓库
 git commit -m "..." 把文件提交到仓库
 git reset --hard HEAD^  版本回退，HEAD^ 指向上个版本
 删除文件 git rm {yourfile}
 撤销修改
 其实是用版本库里的版本替换工作区的版本，
 无论工作区是修改还是删除，都可以“一键还原”。
 git checkout -- {yourfile}

 ~~~~~~~~~ remote guide ~~~~~~~~
 git remote add origin <your_git:account>
 错误提示：fatal: remote origin already exists.
 则使用 git remote rm origin
 git push origin master
 错误提示：error: failed to push some refs to
 错误原因：在推送前没有进行本地仓库和远程服务器的同步
 方法一 git push -f 强制推送，远端仓库被覆盖
 方法二 需先对本地和远程仓库进行整理合并
 git pull --rebase origin master
 git push -u origin master

'
