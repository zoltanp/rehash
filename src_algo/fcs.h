/*
 Copyright (c) 2003, Dominik Reichl <dominik.reichl@t-online.de>
 All rights reserved.

 LICENSE TERMS

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of ReichlSoft nor the names of its contributors may be used
   to endorse or promote products derived from this software without specific
   prior written permission.

 DISCLAIMER

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ___FCS_H___
#define ___FCS_H___

#include "hashalgo.h"

class CFCS16Hash : public CHashAlgorithm
{
public:
	CFCS16Hash();
	~CFCS16Hash();

	const char *GetName() { return "FCS16"; }
	const char *GetShortName() { return "FCS16"; }
	unsigned long GetLength() {	return 2; }
	unsigned long GetInternalLength() { return 2; }

	void Init(RH_DATA_INFO *pInfo);
	void Update(const unsigned char *pBuf, unsigned long uLen);
	void Final();
	void GetHash(unsigned char *pHash) { STORE16H(m_fcs16, pHash); }

private:
	UWORD16 m_fcs16;
};

class CFCS32Hash : public CHashAlgorithm
{
public:
	CFCS32Hash();
	~CFCS32Hash();

	const char *GetName() { return "FCS32"; }
	const char *GetShortName() { return "FCS32"; }
	unsigned long GetLength() { return 4; }
	unsigned long GetInternalLength() { return 4; }

	void Init(RH_DATA_INFO *pInfo);
	void Update(const unsigned char *pBuf, unsigned long uLen);
	void Final();
	void GetHash(unsigned char *pHash) { STORE32H(m_fcs32, pHash); }

private:
	UWORD32 m_fcs32;
};

#endif // ___FCS_H___
