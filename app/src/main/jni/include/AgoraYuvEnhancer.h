/* Copyright(c) 2016, Agora. All rights reserved
 */

#if !defined(__AGORA_YUV_ENHANCER_H__)
#define __AGORA_YUV_ENHANCER_H__

#include "AgoraYuvPreProcessor.h"

/* This class encapsulates skin enhancement algorithm and
 * can be used with Agora video engine to improve skin
 * visually
 */

#if defined(WIN32)
#if defined(EXPORTDLL)
#define IMPORTEXPORT __declspec(dllexport)
#elif defined(IMPORTDLL)
#define IMPORTEXPORT __declspec(dllimport)
#else
#define IMPORTEXPORT
#endif
#else
#define IMPORTEXPORT
#endif

class IMPORTEXPORT AgoraYuvEnhancer : public AgoraYuvPreProcessor
{
public:
	AgoraYuvEnhancer();
	virtual ~AgoraYuvEnhancer();

    // adjust lightening (0 ~ 1.5, inclusive)
    // return value: 0 (ok) or -1 (fail)
    int SetLighteningFactor(float factor);
	// adjust skin smoothness (0 ~ 15, inclusive)
    // return value: 0 (ok) or -1 (fail)
	int SetSmoothnessFactor(int level);

public:
    virtual void ProcessOneFrame(unsigned char *y, unsigned char *u, unsigned char *v,
             int ystride, int ustride, int vstride, int width, int height);

private:
	void *m_pEnhancer;
};


#endif /* __AGORA_YUV_ENHANCER_H__ */

