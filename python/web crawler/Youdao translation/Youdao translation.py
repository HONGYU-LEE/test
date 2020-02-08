import urllib.request
import urllib.parse
import json
import time
while True:
    target = input("请输入需要翻译的内容：")
    url = 'http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule'
    data = {
        'i' : target,
        'from' : 'AUTO',
        'to' : 'AUTO',
        'smartresult' : 'dict',
        'client' : 'fanyideskweb',
        'salt' : '15810537039389',
        'sign' : '157b38258a2253c7899895880487edfd',
        'ts' : '1581053703938',
        'bv' : '901200199a98c590144a961dac532964',
        'doctype' : 'json',
        'version' : '2.1',
        'keyfrom' : 'fanyi.web',
        'action' : 'FY_BY_CLICKBUTTION',    
    }

    head = {'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36'}

    data = urllib.parse.urlencode(data).encode('utf-8')

    rep = urllib.request.Request(url, data, head)
    response = urllib.request.urlopen(rep)

    html = response.read().decode('utf-8')
    result = json.loads(html)
    result = result['translateResult'][0][0]['tgt']

    print(result)
    time.sleep(3);

