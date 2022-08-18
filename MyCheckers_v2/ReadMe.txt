双人对战
1. 双击鼠标/按某个按钮代表完成己方走棋
    chessselected置为-1
    LCM停止计时并归零
2. 判断走法是否合规
    单独记录是否有“挪子”情况，若有：自动结束己方走棋
    计算是否为“跳棋”情况
3. LCM到时间自动换边
    若鼠标尚未release则回到上次press的位置
4. 其他规则：（包括但不限于）
    回合统计
    胜利图像
5. 其它图形界面：
    play->start，play->admit_defeat
    quit,help,score
