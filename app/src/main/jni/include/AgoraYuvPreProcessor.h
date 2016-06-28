/* Copyright(c) 2016, Agora. All rights reserved
 */

#if !defined(__AGORA_YUV_PREPROCESSOR_H__)
#define __AGORA_YUV_PREPROCESSOR_H__

/* This class defines the base class used for preprocessing a
 * captured yuv frame externally
 *
 * How to use
 * 1. Derive this class and implement API ProcessOneFrame()
 * 2. In app, create an object of the derived class
 * 3. Call AgoraYuvPreProcessor::RegisterToEngine(&obj)
 *
 * If want to stop preprocessor, call AgoraYuvPreProcessor::RegisterToEngine(NULL)
 *
 * example code:
   class MyPreProcessor : public AgoraYuvPreProcessor
   {
   public:
       virtual void ProcessOneFrame(unsigned char *y, unsigned char *u, unsigned char *v,
              int ystride, int ustride, int vstride, int width, int height);
       ...
   };
      
   void set_external_preprocessor()
   {
       preprocessor = new MyPreProcessor;
       AgoraYuvPreProcessor::RegisterToEngine(preprocessor);
   }
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

class IMPORTEXPORT AgoraYuvPreProcessor
{
public:
	AgoraYuvPreProcessor();
	virtual ~AgoraYuvPreProcessor();

	// register the processor to engine. if NULL is passed, then deregister from engine
    static void RegisterToEngine(AgoraYuvPreProcessor *processor);

public:
    // callback from engine. process yuv data in this function
    virtual void ProcessOneFrame(unsigned char *y, unsigned char *u, unsigned char *v,
             int ystride, int ustride, int vstride, int width, int height) = 0;
};


#endif /* __AGORA_YUV_PREPROCESSOR_H__ */

