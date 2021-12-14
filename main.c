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

    argc = 4;
    argv[2] = "consultOrderId";
    argv[3] = "userId";

    if (argc <= 1) {
        printf("参数为空，生成失败！\n");
        return -1;
    }

//    char *url = argv[1];

    char url[] = "https://h5.shantaijk.cn/health_report/#/collect";
    printf("初始URL: %s\n", url);

    char h5Suffix[1024];
    char suffix[1024];
    if (argc > 2) {
        for (int i = 2; i < argc; ++i) {
//            printf("参数：%d,value: %s\n", i, argv[i]);
            char *h5Res;
            char *res;
            if (i == 2) {
                h5Res = strAppend(5, "?", argv[i], "={", argv[i], "}");
                res = strAppend(5, "%3F", argv[i], "%3D{", argv[i], "}");
            } else {
                h5Res = strAppend(5, "&", argv[i], "={", argv[i], "}");
                res = strAppend(5, "%26", argv[i], "%3D{", argv[i], "}");
            }
            strcat(suffix, res);
            strcat(h5Suffix, h5Res);
        }
    }

    //H5链接，不需要转换
    char h5Url[1024] = "";
    strcat(h5Url, url);
    strcat(h5Url, h5Suffix);


    //需要编码
    urlEncode(url);
//    printf("URL编码: %s\n", url);
    char xcxUrl[1024] = "xcx://xcx/pages/bridge/webview/index?url=";
    char wxUrl[1024] = "xcx://xcx/pages/bridge/webview/index.html?url=";
    strcat(xcxUrl, url);
    strcat(wxUrl, url);

    strcat(xcxUrl, suffix);
    strcat(wxUrl, suffix);

    printf("---------链接生成---------\n");
    printf("H5链接： %s\n", h5Url);
    printf("小程序链接： %s\n", xcxUrl);
    printf("微信链接： %s\n", wxUrl);

    return 0;
}
