#pragma once
const int HOURS_BOUND = 24;
const int MINUTES_BOUND = 60;
const int SECONDS_BOUND = 60;

class CTime
{
public:
	// Конструирует время (чч:мм:сс).
	// Если часы, минуты, или секунды выходят за пределы 23:59:59, бросает
	// исключение invalid_argument
	CTime(int hours, int minutes, int seconds);

	// Возвращает количество часов (0..23)
	int GetHours() const;

	// Возвращает количество минут (0..59)
	int GetMinutes() const;

	// Возвращает количество секунд (0..59)
	int GetSeconds() const;

	// Возвращает строковое представление времени в формате чч:мм:сс
	std::string ToString() const;

	CTime& operator+=(const CTime& time);
	CTime& operator-=(const CTime& time);
	const CTime operator+(const CTime& time) const;
	const CTime operator-(const CTime& time) const;

private:
	int m_hours;
	int m_minutes;
	int m_seconds;
};

std::ostream& operator<<(std::ostream& strm, const CTime& time);

/*
Реализовать методы класса и перечисленные ниже операции. Сложение и вычитание выполняется в пределах суток
Примеры:
	+	складывает временные интервалы: 23:59:17 + 01:12:13 -> 01:11:30
	-	вычитает временные интервалы: 00:15:25 - 01:16:25 -> 22:59:00
	+=	a += b аналогично a = a + b
	-=	a -= b аналогично a = a - b
	<<	выводит время в заданный ostream в формает чч:мм:сс
*/
