import requests
import bs4

def get_html(url):
    headers = {'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36'}
    response = requests.get(url, headers = headers)

    return response.text

def get_datas(text):
    soup = bs4.BeautifulSoup(text, "html.parser")

    data = []
    animes = soup.find_all("li", class_= "rank-item")
    
    for anime in animes :
        title = anime.find('div','info').a.string
        link = anime.find('div','info').a['href']
        rank = anime.find('div','num').string
        updata = anime.find('div', 'pgc-info').string
        play = anime.find_all('span', class_='data-box')[0].text
        view = anime.find_all('span', class_='data-box')[1].text
        fav = anime.find_all('span', class_='data-box')[2].text
        data.extend([rank, title, updata, play, view, fav, link])

    return data

def grouped(iterable, n):
      return zip(*[iter(iterable)] * n)    

    
def main():
    url = "https://www.bilibili.com/ranking/bangumi/13/0/3?spm_id_from=333.851.b_62696c695f7265706f72745f616e696d65.51"
    text = get_html(url)
    datas = get_datas(text)

    with open('Animation Leaderboard.txt', 'a', encoding = "utf-8") as file:
        for rank, title, updata, play, view, fav, link in grouped(datas, 7):
            file.write(''.join(['排名： ',rank,' 标题： ',title,' 集数： ',updata,' 观看数： ', play,' 评论数: ',view, ' 喜欢数: ', fav, ' 链接 ：',link, '\n']))
            

if __name__ == "__main__":
    main()
