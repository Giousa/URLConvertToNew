#include "BuildURL.h"
#include "utils.h"

void buildKVUrl(int argc, char *argv[]) {

    if (argc <= 1) {
        printf("参数为空，生成失败！\n");
        return;
    }

    char *url = argv[1];
    printf("初始URL: %s\n", url);

    char h5Suffix[1024];
    char suffix[1024];
    if (argc > 2) {
        for (int i = 2; i < argc; ++i) {
//            printf("参数：%d,value: %s\n", i, argv[i]);
            char *h5Res;
            char *res;
            if (i == 2) {
                h5Res = strAppend(5, "?", argv[i], "={{", argv[i], "}}");
                res = strAppend(5, "%3F", argv[i], "%3D{{", argv[i], "}}");
            } else {
                h5Res = strAppend(5, "&", argv[i], "={{", argv[i], "}}");
                res = strAppend(5, "%26", argv[i], "%3D{{", argv[i], "}}");
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
    printf("KV H5链接： %s\n", h5Url);
    printf("KV 小程序链接： %s\n", xcxUrl);
    printf("KV 微信链接： %s\n", wxUrl);
}

void buildLinksUrl(int argc, char *argv[]) {

    if (argc <= 1) {
        printf("参数为空，生成失败！\n");
        return;
    }

    char *url = argv[1];
//    char url[] = "https://h5.shantaijk.cn/health_report/#/collect";
    printf("初始URL: %s\n", url);

    char h5Suffix[1024];
    char suffix[1024];
    if (argc > 2) {
        for (int i = 2; i < argc; ++i) {
//            printf("参数：%d,value: %s\n", i, argv[i]);
            char *h5Res;
            char *res;
            if (i == 2) {
                h5Res = strAppend(5, "?", argv[i], "=${", argv[i], "}");
                res = strAppend(5, "%3F", argv[i], "%3D%24{", argv[i], "}");
            } else {
                h5Res = strAppend(5, "&", argv[i], "=${", argv[i], "}");
                res = strAppend(5, "%26", argv[i], "%3D%24{", argv[i], "}");
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
    printf("Links H5链接： %s\n", h5Url);
    printf("Links 小程序链接： %s\n", xcxUrl);
    printf("Links 微信链接： %s\n", wxUrl);
}