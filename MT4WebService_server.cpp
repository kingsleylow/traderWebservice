// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.
#include "MyAPI.h"
#include "MT4WebService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>

//#include "ws2_32.dll"
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#pragma comment(lib, "libthrift.lib")
#if _WIN32_WINNT < 0x0502
  #define ADDRINFOT addrinfo
  #define GetAddrInfo getaddrinfo
  #define FreeAddrInfo freeaddrinfo
	#define WSAPoll wsapoll
#endif
#pragma   comment(lib,"Ws2_32.lib")

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class MT4WebServiceHandler : virtual public MT4WebServiceIf {
private:
	API _api ;

 public:
  MT4WebServiceHandler() {
    // Your initialization goes here
	 string server = "103.40.162.86:640" ;
     string login = "2" ;
	 string password = "123456a" ;  
	 bool flag = true ;
	 while(flag){
	 cout << "请输入MetaTrader4服务器IP：Port。形如 " << server << endl;
	 string tmp_server ;
	 cin >> tmp_server  ;
	 if(!tmp_server.empty())
		 server = tmp_server ;

	 cout << "请输入manager的login。形如 " << login << endl;
	 string tmp_login;
	 cin >> tmp_login ;
	 if(!tmp_login.empty())
		 login = tmp_login ;

	 cout << "请输入manager的password。"  << endl;
	 string tmp_password;
	 cin >> tmp_password ;
	 if(!tmp_password.empty())
		 password = tmp_password ;
	 int ret=_api.login(server,login,password) ;
	 if(ret!=0){
		 cout << "连接MetaTrader4服务器失败，登陆失败，请重新输入" << endl;
		 flag = true ;
	 }else{
		flag = false ;
	 }
	 }
	 cout << "Web Server Start !" << endl;
	 cout << "Waiting for web request........." << endl ;
	 _api.continueConnection() ;
	 _api.continuePumpConnection() ;
  }

  void getAllUserRecord(std::vector<MT4UserRecord> & _return) {
    // Your implementation goes here
	  cout << "=============================" << endl;
	vector<UserRecord> aur =  _api.getAllUserRecord() ;


	for(int i=0;i<aur.size();i++){

		MT4UserRecord ur  ;
		ur.__set_address(aur.at(i).address) ;
		ur.__set_name(aur.at(i).name) ;
		ur.__set_agent_account(aur.at(i).agent_account) ;
		ur.login = aur.at(i).login ;
		ur.__set_email(aur.at(i).email) ;
		ur.__set_password(aur.at(i).password) ;
		ur.__set_password_investor(aur.at(i).password_investor) ;
		ur.__set_password_phone(aur.at(i).password_phone) ;
		ur.__set_city(aur.at(i).city) ;
		ur.__set_state(aur.at(i).state) ;
		ur.__set_country(aur.at(i).country) ;
		ur.__set_group(aur.at(i).group) ;
		ur.leverage = aur.at(i).leverage ;
		ur.__set_status(aur.at(i).status) ;
		ur.enable = aur.at(i).enable ;
		ur.agent_account = aur.at(i).agent_account ;
		ur.__set_zipcode(aur.at(i).zipcode) ;
		ur.__set_phone(aur.at(i).phone) ;
		ur.__set_id(aur.at(i).id );
		ur.send_reports = aur.at(i).send_reports ;
		ur.__set_comment(aur.at(i).comment) ;
		ur.enable_read_only = aur.at(i).enable_read_only ;
		ur.enable_change_password = aur.at(i).enable_change_password ;
		_return.push_back(ur) ;

	}
    printf("getAllUserRecord\n=============================\n");
  }

  void getUserRecordByLogin(MT4UserRecord& _return, const int32_t login) {
    // Your implementation goes here
	  	  cout << "=============================" << endl;
	  vector<UserRecord> aur =  _api.getUserRecordByLogin(login) ;

	for(int i=0;i<aur.size();i++){
		_return.__set_address(aur.at(i).address) ;
		_return.__set_name(aur.at(i).name) ;
		_return.__set_agent_account(aur.at(i).agent_account) ;
		_return.login = aur.at(i).login ;
		_return.__set_email(aur.at(i).email) ;
		_return.__set_password(aur.at(i).password) ;
		_return.__set_password_investor(aur.at(i).password_investor) ;
		_return.__set_password_phone(aur.at(i).password_phone) ;
		_return.__set_city(aur.at(i).city) ;
		_return.__set_state(aur.at(i).state) ;
		_return.__set_country(aur.at(i).country) ;
		_return.__set_group(aur.at(i).group) ;
		_return.leverage = aur.at(i).leverage ;
		_return.__set_status(aur.at(i).status) ;
		_return.enable = aur.at(i).enable ;
		_return.agent_account = aur.at(i).agent_account ;
		_return.__set_zipcode(aur.at(i).zipcode) ;
		_return.__set_phone(aur.at(i).phone) ;
		_return.__set_id(aur.at(i).id );
		_return.send_reports = aur.at(i).send_reports ;
		_return.__set_comment(aur.at(i).comment) ;
		_return.enable_read_only = aur.at(i).enable_read_only ;
		_return.enable_change_password = aur.at(i).enable_change_password ;
	}
    printf("getUserRecordByLogin\n=============================\n");
  }

   int32_t addUser(const MT4UserRecord& mur) {
    // Your implementation goes here
	  	  	  cout << "=============================" << endl;
	  UserRecord ur ={0} ;
	strcpy(ur.address , mur.address.c_str() );
	strcpy(ur.name , mur.name.c_str() );
	ur.agent_account = mur.agent_account ;
	ur.login = ur.login ;
	strcpy(ur.password , mur.password.c_str() );
	strcpy(ur.email , mur.email.c_str() );
	strcpy(ur.password_investor , mur.password_investor.c_str() );
	strcpy(ur.password_phone , mur.password_phone.c_str() );
	strcpy(ur.city , mur.city.c_str() );
	strcpy(ur.state , mur.state.c_str() );
	strcpy(ur.country , mur.country.c_str() );
	strcpy(ur.group , mur.group.c_str() );
	strcpy(ur.status , mur.status.c_str() );
	strcpy(ur.zipcode , mur.zipcode.c_str() );
	strcpy(ur.phone , mur.phone.c_str() );
	ur.user_color = USER_COLOR_NONE ;
	strcpy(ur.id , mur.id.c_str() );

	ur.leverage = mur.leverage ;
	ur.enable = mur.enable ;
	ur.agent_account = mur.agent_account ;
	strcpy(ur.comment , mur.comment.c_str() );
	ur.send_reports = mur.send_reports ;

	ur.enable_read_only = mur.enable_read_only ;
	ur.enable_change_password = mur.enable_change_password ;

	int ret=_api.addNewUser(ur) ;
	    printf("addUser\n=============================\n");
	if(ret == RET_OK){
		return ur.login ;
	}else{
		return -1 ;
	}
  }

  bool groupOperation(const MT4GroupCommand& mgc) {
    // Your implementation goes here

	 cout << "=============================" << endl;
	  GroupCommandInfo gci={0} ;
	vector<int> u_logins=mgc.user_logins ;
	int * logins = new int[u_logins.size()] ;
	for(int i=0;i<u_logins.size();i++){
		logins[i] = u_logins.at(i) ;
	}
	gci.len = u_logins.size() ;
	char command ;
	switch(mgc.group_opt){
	case MT4GROUP_OPT::G_DELETE:{
		command = GROUP_DELETE ;
		break ;				  
	}
	case MT4GROUP_OPT::G_DISABLE:{
		command = GROUP_DISABLE ;
		break ;
								 }
	case MT4GROUP_OPT::G_LEVERAGE:{
		command = GROUP_LEVERAGE ;
		break ;
								}
	case MT4GROUP_OPT::G_ENABLE:{
		command = GROUP_ENABLE ;
		break ;
								}
	case MT4GROUP_OPT::G_SETGROUP:{
		command = GROUP_SETGROUP ;
		break ;
								}
	}
	gci.command = command ;
	gci.leverage = mgc.leverage ;
	strcpy(gci.newgroup ,mgc.newgroup.c_str()) ;
	int ret=_api.groupOperation(gci,logins) ;
	delete[] logins ;
    printf("groupOperation\n=============================\n");
	if(ret == RET_OK)
		return true ;
	else
		return false ;
  }

  bool balance(const int32_t login, const double money, const MT4DEAL_TYPE::type type, const std::string& comment) {
    // Your implementation goes here
	 cout << "=============================" << endl;
	DEAL_TYPE t ;
	switch(type){
		case MT4DEAL_TYPE::D_IN:{
			t = DEAL_TYPE::D_IN ;
			break;
		}
		case MT4DEAL_TYPE::D_OUT:{
			t = DEAL_TYPE::D_OUT ;
			break;
		}
	}
	int ret=_api.balance(money,login,t,comment) ;
    printf("balance\n=============================\n");
	if(ret == RET_OK)
		return true ;
	else
		return false ;
  }

  bool credit(const int32_t login, const double money, const MT4DEAL_TYPE::type type, const std::string& comment, const int64_t ExpirationDayTimestamp) {
    // Your implementation goes here
	 cout << "=============================" << endl;
	DEAL_TYPE t ;
	switch(type){
		case MT4DEAL_TYPE::D_IN:{
			t = DEAL_TYPE::D_IN ;
			break;
		}
		case MT4DEAL_TYPE::D_OUT:{
			t = DEAL_TYPE::D_OUT ;
			break;
		}
	}
	int ret=_api.credit(money,login,t,comment,ExpirationDayTimestamp) ;
    printf("credit\n=============================\n");
	if(ret == RET_OK)
		return true ;
	else
		return false ;
  }

   bool changePassword(const int32_t login, const std::string& password, \
	   const MT4PASSWORD_TYPE::type p_type, const std::string& new_password) {
    // Your implementation goes here
	 cout << "=============================" << endl;
	PASSWORD_TYPE t ;
	switch(p_type){
		case MT4PASSWORD_TYPE::P_MASTER:{
			t = PASSWORD_TYPE::P_MASTER ;
			break;
		}
		case MT4PASSWORD_TYPE::P_INVEST:{
			t = PASSWORD_TYPE::P_INVESTER ;
			break;
		}
	}
	int ret=_api.changePassword(login,password,new_password,t) ;
	printf("changePassword\n=============================\n");
	if(ret == RET_OK){
		//return ur.login ;
		return true ;
	}else{
		//return -1 ;
		return false ;
	}

  }

  void getTradesHistoryByLogin(std::vector<MT4TradeRecord> & _return, const int32_t login, const int64_t fromTimeStamp, const int64_t toTimeStamp) {
    // Your implementation goes here
	 cout << "=============================" << endl;

	vector<TradeRecord> vc = _api.getTradesHistoryByLogin(login,fromTimeStamp,toTimeStamp) ;
	_return.resize(vc.size()) ;
	for(int i=0;i<vc.size();i++){
		_return.at(i).login = vc.at(i).login ;
		_return.at(i).order = vc.at(i).order ;
		_return.at(i).open_price = vc.at(i).open_price ;
		_return.at(i).close_price = vc.at(i).close_price ;
		_return.at(i).close_time = vc.at(i).close_time ;
		_return.at(i).tp = vc.at(i).tp ;
		_return.at(i).__set_comment(vc.at(i).comment) ;
		_return.at(i).sl = vc.at(i).sl ;
		_return.at(i).commission = vc.at(i).commission ;
		_return.at(i).digits = vc.at(i).digits ;
		_return.at(i).expiration = vc.at(i).expiration ;
		_return.at(i).open_time = vc.at(i).open_time ;
		_return.at(i).volume = vc.at(i).volume ;
		_return.at(i).__set_symbol(vc.at(i).symbol) ;
		_return.at(i).swap = vc.at(i).storage ;
		_return.at(i).profit = vc.at(i).profit ;
	}
    printf("getTradesHistoryByLogin\n=============================\n");
  }

  void getOngingTradesByLogin(std::vector<MT4TradeRecord> & _return, const int32_t login) {
    // Your implementation goes here
	 cout << "=============================" << endl;
	  vector<TradeRecord> vc = _api.getOngoingTradesByLogin(login) ;
	  	_return.resize(vc.size()) ;
	for(int i=0;i<vc.size();i++){
		_return.at(i).login = vc.at(i).login ;
		_return.at(i).order = vc.at(i).order ;
		_return.at(i).open_price = vc.at(i).open_price ;
		_return.at(i).close_price = vc.at(i).close_price ;
		_return.at(i).close_time = vc.at(i).close_time ;
		_return.at(i).tp = vc.at(i).tp ;
		_return.at(i).__set_comment(vc.at(i).comment) ;
		_return.at(i).sl = vc.at(i).sl ;
		_return.at(i).commission = vc.at(i).commission ;
		_return.at(i).digits = vc.at(i).digits ;
		_return.at(i).expiration = vc.at(i).expiration ;
		_return.at(i).open_time = vc.at(i).open_time ;
		_return.at(i).volume = vc.at(i).volume ;
		_return.at(i).__set_symbol(vc.at(i).symbol) ;
		_return.at(i).swap = vc.at(i).storage ;
		_return.at(i).profit = vc.at(i).profit ;
	}
    printf("getOngingTradesByLogin\n=============================\n");
  }

  void getAllOngoingTrades(std::vector<MT4TradeRecord> & _return) {
    // Your implementation goes here
	 cout << "=============================" << endl;
	  vector<TradeRecord> vc = _api.getAllOngoingTrades() ;
	  	_return.resize(vc.size()) ;
	for(int i=0;i<vc.size();i++){
		_return.at(i).login = vc.at(i).login ;
		_return.at(i).order = vc.at(i).order ;
		_return.at(i).open_price = vc.at(i).open_price ;
		_return.at(i).close_price = vc.at(i).close_price ;
		_return.at(i).close_time = vc.at(i).close_time ;
		_return.at(i).tp = vc.at(i).tp ;
		_return.at(i).__set_comment(vc.at(i).comment) ;
		_return.at(i).sl = vc.at(i).sl ;
		_return.at(i).commission = vc.at(i).commission ;
		_return.at(i).digits = vc.at(i).digits ;
		_return.at(i).expiration = vc.at(i).expiration ;
		_return.at(i).open_time = vc.at(i).open_time ;
		_return.at(i).volume = vc.at(i).volume ;
		_return.at(i).__set_symbol(vc.at(i).symbol) ;
		_return.at(i).swap = vc.at(i).storage ;
		_return.at(i).profit = vc.at(i).profit ;
	}
    printf("getAllOngoingTrades\n=============================\n");
  }

void symbolDetail(MT4ConSymbol& _return, const std::string& symbol) {
    // Your implementation goes here
	cout << "symbolDetail=============================start" << endl;
		
	ConSymbol  conSym=_api.symbolDetail(symbol) ;
	_return.ask_tickvalue=conSym.ask_tickvalue ;
	_return.bid_tickvalue=conSym.bid_tickvalue ;
	_return.__set_symbol(conSym.symbol) ;
	_return.__set_description(conSym.description) ;
	_return.__set_source(conSym.source) ;
	_return.__set_currency(conSym.currency) ;
	_return.type=conSym.type ;
	_return.digits=conSym.digits ;
	_return.trade=conSym.trade ;
	_return.count=conSym.count ;
	_return.count_original=conSym.count_original ;
	_return.realtime=conSym.realtime ;
	_return.starting=conSym.starting ;
	_return.expiration=conSym.expiration ;

	vector<MT4ConSessions> mcons ;
	for(int j=0;j<7;j++){
		
		MT4ConSessions mcon ;
		ConSessions con= conSym.sessions[j] ;
		mcon.trade_overnight = con.trade_overnight ;
		mcon.quote_overnight = con.quote_overnight ;
		for(int k=0;k<3;k++){
			
			ConSession qcs = con.quote[k] ;
			ConSession tcs = con.trade[k] ;
			MT4ConSession mqcs ;
			MT4ConSession  tqcs ;
			mqcs.open_min = qcs.open_min ;
			mqcs.open_hour = qcs.open_hour ;
			mqcs.close_hour = qcs.close_hour ;
			mqcs.close_min = qcs.close_min ;
			mqcs.open = qcs.open ;
			mqcs.close = qcs.close ;
			tqcs.open_min = tcs.open_min ;
			tqcs.open_hour = tcs.open_hour ;
			tqcs.close_hour = tcs.close_hour ;
			tqcs.close_min = tcs.close_min ;
			tqcs.open = tcs.open ;
			tqcs.close = tcs.close ;
			vector<short> mqalign ;
			vector<short> tqalign ;
			for(int d=0;d<7;d++){
				//cout << "DEBUG: "<<d << endl;
				mqalign.push_back(qcs.align[d]) ;
				tqalign.push_back(tcs.align[d]) ;
				//cout << "DEBUG: " << "ss" << endl ;
			}
			mqcs.align = mqalign ;
			tqcs.align = tqalign ;
			mcon.quote.push_back(mqcs) ;
			mcon.trade.push_back(tqcs) ;
		}
		mcons.push_back(mcon) ;
	}
	_return.sessions = mcons ;

	_return.profit_mode=conSym.profit_mode ;
	_return.profit_reserved=conSym.profit_reserved ;
	_return.filter=conSym.filter ;
	_return.filter_counter=conSym.filter_counter ;
	_return.filter_limit=conSym.filter_limit ;
	_return.filter_smoothing=conSym.filter_smoothing ;
	_return.filter_reserved=conSym.filter_reserved ;
	_return.logging=conSym.logging ;
	_return.spread=conSym.spread ;
	_return.spread_balance=conSym.spread_balance ;
	_return.exemode=conSym.exemode ;
	_return.swap_enable=conSym.swap_enable ;
	_return.swap_type=conSym.swap_type ;
	_return.swap_long=conSym.swap_long ;
	_return.swap_short=conSym.swap_short ;
	_return.swap_rollover3days=conSym.swap_rollover3days ;
	_return.contract_size=conSym.contract_size ;
	_return.tick_value=conSym.tick_value ;
	_return.tick_size=conSym.tick_size ;
	_return.stops_level=conSym.stops_level ;
	_return.gtc_pendings=conSym.gtc_pendings ;
	_return.margin_mode=conSym.margin_mode ;
	_return.margin_initial=conSym.margin_initial ;
	_return.margin_maintenance=conSym.margin_maintenance ;
	_return.margin_hedged=conSym.margin_hedged ;
	_return.margin_divider=conSym.margin_divider ;
	_return.point=conSym.point ;
	_return.multiply=conSym.multiply ;
	_return.long_only=conSym.long_only ;
	_return.instant_max_volume=conSym.instant_max_volume ;
	_return.__set_margin_currency(conSym.margin_currency) ;
	_return.freeze_level=conSym.freeze_level ;
	_return.margin_hedged_strong=conSym.margin_hedged_strong ;
	_return.value_date=conSym.value_date ;
	_return.quotes_delay=conSym.quotes_delay ;
	_return.swap_openprice=conSym.swap_openprice ;

    printf("symbolDetail====================================end\n");
  }

  void getHistoryChartData(std::vector<MT4RateInfo> & _return, const MT4ChartInfo& chartInfo) {
 cout << "getHistoryChartData=============================start" << endl;
	int total =0;
   __time32_t signTime= 0;
   ChartInfo ci ;
	int type ;
   	switch(chartInfo.period){
	case MT4PERIOD_TYPE::P_PERIOD_M1:{
			type = PERIOD_M1 ;
			break;
		}
	case MT4PERIOD_TYPE::P_PERIOD_M5:{
			type = PERIOD_M5 ;
			break;
		}
	case MT4PERIOD_TYPE::P_PERIOD_M15:{
			type = PERIOD_M15 ;
			break;
		}
	case MT4PERIOD_TYPE::P_PERIOD_M30:{
			type = PERIOD_M30 ;
			break;
		}
	case MT4PERIOD_TYPE::P_PERIOD_H1:{
			type = PERIOD_H1 ;
			break;
		}
	case MT4PERIOD_TYPE::P_PERIOD_H4:{
			type = PERIOD_H4 ;
			break;
		}
	case MT4PERIOD_TYPE::P_PERIOD_D1:{
			type = PERIOD_D1 ;
			break;
		}
	case MT4PERIOD_TYPE::P_PERIOD_W1:{
			type = PERIOD_W1 ;
			break;
		}
	case MT4PERIOD_TYPE::P_PERIOD_MN1:{
			type = PERIOD_MN1 ;
			break;
		}
	default:
		type = PERIOD_H4 ;
	}
	strcpy(ci.symbol,chartInfo.symbol.c_str());
	ci.period = type ;
	ci.timesign = chartInfo.timesign ;
	switch(chartInfo.mode){
	case MT4CHART_TYPE::C_CHART_RANGE_IN:{
		ci.mode=CHART_RANGE_IN;
		break ;
		}
	case MT4CHART_TYPE::C_CHART_RANGE_LAST:{
		ci.mode=CHART_RANGE_LAST;
		break ;
		}
	case MT4CHART_TYPE::C_CHART_RANGE_OUT:{
		ci.mode=CHART_RANGE_OUT;
		break ;
		}
	}
	
	ci.end =chartInfo._end ;
	cout << "DEBUG: end " << ci.end << endl ;
	ci.start =chartInfo.start;
	cout << "DEBUG: start " << ci.start << endl ;
	cout << "DEBUG: period " << ci.period << " mins" << endl ;
		cout << "DEBUG: mode " << ci.mode << endl ;
  int digit=0;
   vector<RateInfo>  ri;
   try{
	  
		ri=_api.getHistoryChartData(ci,digit) ;
	
   }catch(exception &e){
	   cout << e.what() << endl ;
   }
   _return.resize(ri.size()) ;
   double base = pow(10.0,digit) ;
   for(int i=ri.size()-1;i>=0;i--){
	   _return.at(i).open=ri.at(i).open*1.0/base ;
	   _return.at(i).close=ri.at(i).close*1.0/base ;
	  // cout << "DEBUG: time" <<ri.at(i).ctm << endl ;
	   _return.at(i).ctm=ri.at(i).ctm ;
	   _return.at(i).high=ri.at(i).high*1.0/base ;
	   _return.at(i).low=ri.at(i).low*1.0/base ;
	   _return.at(i).vol=ri.at(i).vol ;
   }
    printf("getHistoryChartData====================================end\n");
  }
    



  void getAllGroups(std::vector<MT4ConGroup> & _return) {
   cout << "=============================" << endl;
   vector<ConGroup> vc = _api.allGroups() ;
	  	_return.resize(vc.size()) ;
	for(int i=0;i<vc.size();i++){
		_return.at(i).adv_security = vc.at(i).adv_security ;
		_return.at(i).__set_group(vc.at(i).group) ;
		_return.at(i).__set_company(vc.at(i).company) ;
		_return.at(i).__set_signature(vc.at(i).signature) ;
		_return.at(i).__set_support_page(vc.at(i).support_page) ;
		_return.at(i).__set_smtp_server(vc.at(i).smtp_server) ;
		_return.at(i).__set_smtp_login(vc.at(i).smtp_login) ;
		_return.at(i).__set_smtp_password(vc.at(i).smtp_password) ;
		_return.at(i).__set_templates(vc.at(i).templates) ;
		_return.at(i).copies = vc.at(i).copies ;
		_return.at(i).reports = vc.at(i).reports ;
		_return.at(i).credit = vc.at(i).credit ;
		_return.at(i).__set_reports(vc.at(i).reports) ;
		_return.at(i).currency = vc.at(i).currency ;
		_return.at(i).default_deposit = vc.at(i).default_deposit ;
		_return.at(i).default_leverage = vc.at(i).default_leverage ;
		_return.at(i).margin_call = vc.at(i).margin_call ;
		_return.at(i).margin_mode = vc.at(i).margin_mode ;
		_return.at(i).margin_stopout = vc.at(i).margin_stopout ;
		_return.at(i).interestrate = vc.at(i).interestrate ;
		_return.at(i).use_swap = vc.at(i).use_swap ;
		_return.at(i).enable = vc.at(i).enable ;
		_return.at(i).timeout = vc.at(i).timeout ;
	}
    printf("getAllGroups\n=============================\n");
 
  }



	







  void testSayHi() {
    // Your implementation goes here
    printf("testSayHi\n");
  }

};

int main(int argc, char **argv) {
  int port = 9091;
  boost::shared_ptr<MT4WebServiceHandler> handler(new MT4WebServiceHandler());
  boost::shared_ptr<TProcessor> processor(new MT4WebServiceProcessor(handler));
  boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TThreadedServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

