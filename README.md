t_time	ft_get_time(void)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

struct timeval tipinde bir değişken olan tv tanımlanır. Bu yapı, saniye ve mikrosaniye cinsinden zaman bilgisini içerir.

gettimeofday işlevi, sistem saati ile ilgili ayrıntıları almak için kullanılır. İki argüman alır: birincisi struct timeval türünden bir değişken (burada tv), diğeri ise timezone bilgisi içindir ve genellikle NULL olarak bırakılır.

time değişkeni, elde edilen zaman bilgisiyle güncellenir. Saniye cinsinden olan tv.tv_sec ifadesi 1000 ile çarpılır (milisaniyeye çevrildi) ve tv.tv_usec ifadesi 1000'e bölünür (yine milisaniye cinsine çevrildi). Bu iki değer toplanarak toplam zaman bilgisini milisaniye cinsinden içeren time değişkenine atanır.

Son olarak, hesaplanan zaman bilgisi time değişkeni aracılığıyla döndürülür.
