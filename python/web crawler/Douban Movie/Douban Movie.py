import requests
import bs4

def get_html(url):
    proxies = {"http": "36.25.243.51", "http": "39.137.95.70", "http": "59.56.28.199"}
    headers = {'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36'}
    response = requests.get(url, headers = headers, proxies = proxies)

    return response.text

def get_datas(text):
    soup = bs4.BeautifulSoup(text, "html.parser")
    datas = soup.find_all('div', class_ = 'info')
    
    for each in datas:
        title = each.a.span.text
        introduction = each.p.text.strip()
        score = each.find('span', class_ = 'rating_num').text
        
        data.extend([title, introduction, score])
    
    return data

def Slicing(iterable, n):
      return zip(*[iter(iterable)] * n)    

    
def main():
    host = "https://movie.douban.com/top250"
    text = get_html(host)
    datas = get_datas(text)
    data = []
    index = 1
  
    for i in range(10):
        url = host + '/?start=' + str(25 * i) + '&filter='
        text = get_html(url) 
        datas.extend(get_datas(text))
   
    with open('豆瓣电源top250.txt', 'w', encoding = "utf-8") as file:
        for title, introduction, score in Slicing(datas, 3):
            file.write(''.join(['排名：', str(index), '\n', title, '\n', introduction, '\t评分：', score, '\n']))
            index += 1
            

if __name__ == "__main__":
    main()

