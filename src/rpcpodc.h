// Copyright (c) 2014-2017 The D�sh Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RPCPODC_H
#define RPCPODC_H

#include "hash.h"
#include "net.h"
#include "utilstrencodings.h"
#include <string>
#include <univalue.h>

struct Researcher
{
	std::string nickname;
	int teamid = 0;
	std::string country;
	int64_t creationtime = 0;
	double totalcredit = 0;
	double wcgpoints = 0;
	double rac = 0;
	int id = 0;
	std::string cpid;
	bool found = false;
	bool unbanked = false;
	double CoinAge = 0;
	std::string CPK;
};

std::string strReplace(std::string& str, const std::string& oldStr, const std::string& newStr);
double GetCryptoPrice(std::string sURL);
bool SignStake(std::string sBitcoinAddress, std::string strMessage, std::string& sError, std::string& sSignature);
std::string GetGithubVersion();
std::string SerializeSanctuaryQuorumTrigger(int iContractAssessmentHeight, int nEventBlockHeight, std::string sContract);
bool VerifySigner(std::string sXML);
double GetPBase(double& out_BTC);
std::string GetCPID();
bool GetTransactionTimeAndAmount(uint256 txhash, int nVout, int64_t& nTime, CAmount& nAmount);
std::string SendBlockchainMessage(std::string sType, std::string sPrimaryKey, std::string sValue, double dStorageFee, bool Sign, std::string sExtraPayload, std::string& sError);
std::string ToYesNo(bool bValue);
bool VoteForGobject(uint256 govobj, std::string sVoteOutcome, std::string& sError);
int64_t GetDCCFileAge();
std::string GetSANDirectory2();
int GetWCGMemberID(std::string sMemberName, std::string sAuthCode, double& nPoints);
Researcher GetResearcherByID(int nID);
std::map<std::string, Researcher> GetPayableResearchers();

#endif
