#include <stdio.h>
#include <string.h>
#include "URLEnDecode.h"
#include "utils.h"


/**
 * https://h5.shantaijk.cn/health_report/#/collect?bizType=CONSULT_ORDER_ID&bizId={consultOrderId}
 * 转换为：
 * xcx://xcx/pages/bridge/webview/index?url=https%3A%2F%2Fh5.shantaijk.cn%2Fhealth_report%2F%23%2Fcollect%3FbizType%3DCONSULT_ORDER_ID%26bizId%3D{consultOrderId}
 * @return
 */
int main(int argc, char *argv[]) {

//    printf("argc num: %d\n", argc);

//    argc = 4;
//    argv[2] = "consultOrderId";
//    argv[3] = "userId";

    if (argc <= 1) {
        printf("参数为空，生成失败！\n");
        return -1;
    }

    char *url = argv[1];
//    char url[] = "https://h5.shantaijk.cn/health_report/#/collect";
    printf("初始URL: %s\n", url);

    char suffix[1024];
    if (argc > 2) {
        for (int i = 2; i < argc; ++i) {
//            printf("参数：%d,value: %s\n", i, argv[i]);
            char *res;
            if (i == 2) {
                res = strAppend(5, "%3F", argv[i], "%3D{", argv[i], "}");
            } else {
                res = strAppend(5, "%26", argv[i], "%3D{", argv[i], "}");
            }
            strcat(suffix,res);
        }
    }

    urlEncode(url);
//    printf("URL编码: %s\n", url);

    char xcxUrl[1024] = "xcx://xcx/pages/bridge/webview/index?url=";
    char wxUrl[1024] = "xcx://xcx/pages/bridge/webview/index.html?url=";
    strcat(xcxUrl, url);
    strcat(wxUrl, url);

    strcat(xcxUrl, suffix);
    strcat(wxUrl, suffix);

    printf("---------链接生成---------\n");
    printf("小程序链接： %s\n", xcxUrl);
    printf("微信链接： %s\n", wxUrl);

    return 0;
}
