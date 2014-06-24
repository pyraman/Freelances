
#ifndef DEVICEINFO_IOS_H_
#define DEVICEINFO_IOS_H_

#include "AbtList.h"

using namespace std;


class WindowInfo;
class AgentInfo;
class DeviceInfo;

typedef AbtList<WindowInfo> AbtWinInfoList;
typedef AbtList<AgentInfo> AbtAgentInfoList;

enum enuDevRunMode
{
	E_DEV_RUN_WIFI_MODE = 0,
	E_DEV_RUN_USB_MODE = 1
};

#define COLON_DELIMITER			":"
#define SEMICOLON_DELIMITER		";"
#define HATCH_DELIMITER			"/"

/************************************************************************/
/* Device Info Section                                                  */
/************************************************************************/
class DeviceInfo
{
public:
	DeviceInfo();
	DeviceInfo(string aDeviceUniqueId, string aDeviceId, enuDevRunMode aRunMode);
	DeviceInfo(string aDeviceUniqueId, string aDeviceId, string aManufacturer, string aModelName);
	~DeviceInfo();

	void setDeviceUniqueId(string aDeviceUniqueId);
	string getDeviceUniqueId();
	void setDeviceId(string aDeviceId);
	const char* getDeviceId();
	void setDeviceName(string aDeviceName);
	const char* getDeviceName();
	void setDeviceOS(string aDeviceOS);
	const char* getDeviceOS();
	void setManufacturer(string aManufacturer);
	string getManufacturer();
	void setModelName(string aModelName);
	string getModelName();
	void setIpAddress(string aIpAddress);
	string getIpAddress();
	void setIpPort(string aIpPort);
	string getIpPort();
	void setRunMode(enuDevRunMode aRunMode);
	bool isWiFiMode();
	bool isUSBMode();
	void resetDeviceInfo();
private:
	void init();

private:
	string mDeviceUniqueId;
	string mDeviceId;
	string mManufacturer;
	string mModelName;
	string mIpAddress;
	string mIpPort;
	string mDeviceName;
	string mDeviceOS;
	enuDevRunMode mRunMode;
};

/************************************************************************/
/* Agent Info Section                                                   */
/************************************************************************/
class AgentInfo
{
public:
	AgentInfo();
	~AgentInfo();

	void setHost(string aHost);
	string getHost();
	void setPort(string aPort);
	string getPort();
	void addWindowInfo(WindowInfo* apWinInfo);
	AbtWinInfoList* getWinInfoList();
	void parseAgentInfo(string aAgentInfo);

private:
	string mHost;
	string mPort;
	AbtWinInfoList mWinInfoList;
};

/************************************************************************/
/* Window Info Section                                                  */
/************************************************************************/
class WindowInfo
{
public:
	WindowInfo();
	~WindowInfo();

	void setUniqueKey(string aUniqueKey);
	string getUniqueKey();
	void setSignature(string aSignature);
	string getSignature();

private:
	string mUniqueKey;
	string mSignature;
};

#endif /* DEVICEINFO_IOS_H_ */


