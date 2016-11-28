// datetime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <boost/date_time.hpp>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
namespace bt = boost::posix_time;
/*
const std::locale formats[] = {
	std::locale(std::locale::classic(),new bt::time_input_facet("%Y-%m-%d %H:%M:%S")),
	std::locale(std::locale::classic(),new bt::time_input_facet("%Y/%m/%d %H:%M:%S")),
	std::locale(std::locale::classic(),new bt::time_input_facet("%d.%m.%Y %H:%M:%S")),
	std::locale(std::locale::classic(),new bt::time_input_facet("%Y-%m-%d")) };
const size_t formats_n = sizeof(formats) / sizeof(formats[0]);


std::time_t pt_to_time_t(const bt::ptime& pt)
{
	bt::ptime timet_start(boost::gregorian::date(1970, 1, 1));
	bt::time_duration diff = pt - timet_start;
	return diff.ticks() / bt::time_duration::rep_type::ticks_per_second;

}

void seconds_from_epoch(const std::string& s)
{
	bt::ptime pt;
	for (size_t i = 0; i<formats_n; ++i)
	{
		std::istringstream is(s);
		is.imbue(formats[i]);
		is >> pt;
		if (pt != bt::ptime()) break;
	}
	std::cout << " ptime is " << pt << '\n';
	std::cout << " seconds from epoch are " << pt_to_time_t(pt) << '\n';
}
*/
std::locale inputs[] = {
	std::locale(std::locale::classic(), new bt::time_input_facet("%m/%d/%Y")),
	std::locale(std::locale::classic(), new bt::time_input_facet("%Y-%m-%d %H:%M:%S")),
	std::locale(std::locale::classic(), new bt::time_input_facet("%Y%m%d%H%M%S")),
	std::locale(std::locale::classic(), new bt::time_input_facet("%Y%m%d%H%M")),
	std::locale(std::locale::classic(), new bt::time_input_facet("%Y%m%d")) };
const size_t formats = sizeof(inputs) / sizeof(inputs[0]);

time_t ptime_to_time_t(boost::posix_time::ptime t)
{
	static boost::posix_time::ptime epoch(boost::gregorian::date(1970, 1, 1));
	return (t - epoch).ticks() / boost::posix_time::time_duration::ticks_per_second();
}

int main()
{
	std::string msg = "2010-08-04 08:34:12";

	bt::ptime abs_time;
	bt::time_input_facet *tif = new bt::time_input_facet("%Y-%m-%d %H:%M:%S");
	std::istringstream iss(msg);
	std::locale temp = std::locale(std::locale::classic(), tif);
	iss.imbue(temp);
	iss >> abs_time;
	std::cout << abs_time << std::endl;

	bt::ptime this_time;
	std::locale temp2 = std::locale(std::locale::classic(), new bt::time_input_facet("%Y-%m-%d %H:%M:%S"));
	std::istringstream ss(msg);
	ss.imbue(temp2);
	ss >> this_time;
	std::cout << this_time << std::endl;

	bt::ptime this_time2;
	std::locale temp3 = inputs[1];
	std::istringstream jss(msg);
	jss.imbue(temp3);
	jss >> this_time2;
	std::cout << this_time2 << std::endl;

	/*
	for (size_t i = 0; i<formats; ++i)
	{
		std::istringstream ss(msg);
		ss.imbue(inputs[i]);
		bt::ptime this_time;
		ss >> this_time;

		if (this_time != boost::posix_time::not_a_date_time)
			std::cout << this_time << " or " << ptime_to_time_t(this_time) << std::endl;
	}
	*/
	/*
	const boost::posix_time::ptime time =
		boost::posix_time::time_from_string("2015.05.27 08:05:00");

	//const boost::posix_time::ptime time =
	//	boost::posix_time::time_from_string("1981-08-20 08:05:00");

	// ptime to string.
	const std::string str_time = to_simple_string(time);
	std::cout << str_time << std::endl;

	// ptime to stringstream to string.
	std::stringstream stream;
	stream << time;
	std::cout << stream.str() << std::endl;
	stream.str("");

	// Use a facet to display time in a custom format (only hour and minutes).
	boost::posix_time::time_facet* facet = new boost::posix_time::time_facet();
	facet->format("%H:%M");
	stream.imbue(std::locale(std::locale::classic(), facet));
	stream << time;
	std::cout << stream.str() << std::endl;
	*/
	//std::cout << bt::ptime::to_iso_string(abs_time) << std::end;
	/*
	bt::ptime t2;
	std::stringstream iss("2012/04/21 04:34:54");
	ss >> t2;
	*/


	/*
	seconds_from_epoch("2004-03-21 12:45:33");
	seconds_from_epoch("2004/03/21 12:45:33");
	seconds_from_epoch("23.09.2004 04:12:21");
	seconds_from_epoch("2003-02-11");
	*/
	getchar();
}