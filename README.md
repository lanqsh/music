此工程仅作交流用处,请支持正版音乐

/Users/xxx/Library/Containers/com.netease.163music/Data/Library/Caches/online_play_cache		//音乐缓存位置
/Users/xx/Library/Containers/com.netease.163music/Data/Documents/storage/Logs		//日志缓存位置

异或 0xa3

1010 0011	163

0000 0001 ^| 0xa3
|
1010 0010	再异或一次
|
0000 0001	结论:一个数异或同一个数两次得到这个数本身

json歌单:
{"playid":"31134451_1_710563","volumeDelta":-5.33,"songName":"心做し","albumName":"心做し","artistName":"まじ娘","albumId":"album3112341","url":"http://p3.music.126.net/CJ7olt52TMdqvamN7EhkIQ==/7735064301958473.jpg","starttime":0,"duration":274.024,"bitrate":320,"playbrt":320,"type":4,"md5":"a2df4077da5c5187840ba934c449396d","format":"mp3","songId":"31134451","fileSize":10963112,"musicurl":"http://m8c.music.126.net/20181006013039/3d8f4e2473eb438a9b9f84ab7337908f/ymusic/5679/35e1/4a37/a2df4077da5c5187840ba934c449396d.mp3","songType":"normal"}

music缓存名字:
31134451-_-_320-_-_a2df4077da5c5187840ba934c449396d.uc!

在本地已下载的音乐json形式:
{"playid":"33522489_1_710563","volumeDelta":0,"songName":"Summer Vibe (Pegato Remix)","albumName":" Summer Vibe (Pegato Remix)","artistName":"Pegato/Walk off the Earth","albumId":"album3222204","url":"http://p4.music.126.net/Va_olgI_wJlGIgwu57abug==/7935175419222495.jpg","starttime":0,"duration":213.449,"bitrate":320,"playbrt":320,"type":0,"file":"/Users/Lanquanshan/Music/iTunes/iTunes Media/Music/Pegato_Walk off the Earth/_Summer Vibe (Pegato Remix)/Summer Vibe (Pegato Remix).mp3","songType":"normal"}

程序流程,读取歌单,查找是否本地已下载的音乐,若果不是,则读取缓存的音乐,异或后保存到指定文件夹
TODO:加入封面等信息