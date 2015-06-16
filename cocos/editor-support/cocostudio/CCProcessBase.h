/****************************************************************************
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CCPROCESSBASE_H__
#define __CCPROCESSBASE_H__

#include "cocostudio/CCArmatureDefine.h"
#include "cocostudio/CCDatas.h"
#include "cocostudio/CocosStudioExport.h"

namespace cocostudio {


enum AnimationType
{
    SINGLE_FRAME = -4,          //! the animation just have one frame
    ANIMATION_NO_LOOP,          //! the animation isn't loop

    ANIMATION_TO_LOOP_FRONT,    //! the animation loop from front
    ANIMATION_TO_LOOP_BACK,     //! the animation loop from back

    ANIMATION_LOOP_FRONT,       //! the animation loop from front
    ANIMATION_LOOP_BACK,        //! the animation loop from back

    ANIMATION_MAX,

};

/**
 *  @js NA
 *  @lua NA
 */
class  CC_STUDIO_DLL ProcessBase : public cocos2d::Ref
{
public:
    ProcessBase(void);
    virtual ~ProcessBase(void);

    /**
     * @~english Play animation by animation name.
     * @~chinese ���ݶ������Ʋ��Ŷ�����
     *
     * @param  durationTo @~english The frames between two animation changing-over.
     *         It's meaning is changing to this animation need how many frames
     *
     *         -1 : use the value from MovementData get from flash design panel
     * @~chinese ���������л�ʱ����Ҫ��֡������ζ���л����ö���ʱ��Ҫ����֡��
     *    -1��ʹ��Flash����������MovementData�е�ֵ
     *
     * @param  durationTween  @~english The frame count you want to play in the game.
     *         if  _durationTween is 80, then the animation will played 80 frames in a loop
     *
     *         -1 : use the value from MovementData get from flash design panel
     * @~chinese Ҫ����Ϸ�в��ŵ�֡������������ó�80�����ڶ�������ѭ����ÿ�β���80֡��
     * -1��ʹ��Flash����������MovementData�е�ֵ
     *
     * @param  loop @~english   Whether the animation is loop
     *
     *         loop < 0 : use the value from MovementData get from flash design panel
     *         loop = 0 : this animation is not loop
     *         loop > 0 : this animation is loop
     * @~chinese �����Ƿ�ѭ����
     *         loop < 0 : ʹ��Flash����������MovementData�е�ֵ
     *         loop = 0 : ��ѭ��
     *         loop > 0 : ѭ��
     *
     * @param  tweenEasing @~english Tween easing is used for calculate easing effect
     *
     *         TWEEN_EASING_MAX : use the value from MovementData get from flash design panel
     *         -1 : fade out
     *         0  : line
     *         1  : fade in
     *         2  : fade in and out
     * @~chinese ֡���仺���������㻺��Ч��
     *         TWEEN_EASING_MAX : ʹ��Flash����������MovementData�е�ֵ
     *         -1 : ����
     *         0  : ����
     *         1  : ����
     *         2  : ���뵭��
     *
     */
    virtual void play(int durationTo, int durationTween,  int loop, int tweenEasing);

    /**
     * @~english Pause the Process
     * @~chinese ��ͣ����
     */
    virtual void pause();
    /**
     * @~english Resume the Process
     * @~chinese �ָ�����
     */
    virtual void resume();
    /**
     * @~english Stop the Process
     * @~chinese ֹͣ����
     */
    virtual void stop();


    /**
     * @~english You should never call this function, unless you know what you do
     * Update the Process, include current process, current frame and son on
     * @~chinese �˷�����Ӧ�����ã�������֪��Ҫ�������顣���½��ȣ�������ǰ���ȣ���ǰ֡�ȵȡ�
     *
     * @param dt @~english The duration since last update
     * @~chinese ���ϴ�updat�����ڵ�ʱ������
     */
    virtual void update(float dt);

    /**
    * @~english Get current frame index.
    * @~chinese ��ȡ��ǰ֡������
    * @return @~english Current frame index.
    * @~chinese ��ǰ֡������
    */
    virtual int getCurrentFrameIndex();

    /**
    * @~english Set process scale.
    * @~chinese ���ý�������ֵ��
    * @param processScale @~english Process scale.
    * @~chinese ��������ֵ��
    */
    virtual void setProcessScale(float processScale) { _processScale = processScale; }
    /**
    * @~english Get process scale.
    * @~chinese ��ȡ��������ֵ��
    * @return @~english Process scale.
    * @~chinese ��������ֵ��
    */
    virtual float getProcessScale() const { return _processScale; }

    /**
    * @~english Set is pause.
    * @~chinese �����Ƿ���ͣ��
    * @param pause @~english Is pause.
    * @~chinese �Ƿ���ͣ��
    */
    virtual void setIsPause(bool pause) { _isPause = pause; }
    /**
    * @~english Get is pause.
    * @~chinese ��ȡ�Ƿ���ͣ��
    * @return @~english Is pause.
    * @~chinese �Ƿ���ͣ��
    */
    virtual bool isPause() const { return _isPause; }

    /**
    * @~english Set is complete.
    * @~chinese �����Ƿ���ɡ�
    * @param complete @~english Is complete.
    * @~chinese �Ƿ���ɡ�
    */
    virtual void setIsComplete(bool complete) { _isComplete = complete; }
    /**
    * @~english Get is complete.
    * @~chinese ��ȡ�Ƿ���ɡ�
    * @return @~english Is complete.
    * @~chinese �Ƿ���ɡ�
    */
    virtual bool isComplete() const { return _isComplete; }

    /**
    * @~english Set is playing.
    * @~chinese �����Ƿ��ڲ��š�
    * @param complete @~english Is playing.
    * @~chinese �Ƿ��ڲ��š�
    */
    virtual void setIsPlaying(bool playing) { _isPlaying = playing; }
    /**
    * @~english Set is playing.
    * @~chinese �����Ƿ��ڲ��š�
    * @return @~english Is playing.
    * @~chinese �Ƿ��ڲ��š�
    */
    virtual bool isPlaying() const { return _isPlaying; }

    /**
    * @~english Get current percent.
    * @~chinese ��ȡ��ǰ���ȡ�
    * @return @~english Current percent.
    * @~chinese ��ǰ���ȡ�
    */
    virtual float getCurrentPercent() const { return _currentPercent; }

    /**
    * @~english Get raw duration.
    * @~chinese ��ȡԭʼ�ܳ���
    * @return @~english Raw duration.
    * @~chinese ԭʼ�ܳ���
    */
    virtual int getRawDuration() const { return _rawDuration; }

protected:

    virtual void gotoFrame(int frameIndex);

    /**
     * Update(float dt) will call this handler, you can handle your logic here
     */
    virtual void updateHandler() {};

protected:
    //! Scale the process speed
    float _processScale;

    //! Set and get whether the aniamtion is pause
    bool _isPause;

    //! Set and get whether the aniamtion is complete
    bool _isComplete;

    //! Set and get whether the aniamtion is playing
    bool _isPlaying;

    //! Current percent this process arrived
    float _currentPercent;

    //! The raw duration
    int _rawDuration;

    //! The animation whether or not loop
    AnimationType _loopType;

    //! The tween easing effect
    cocos2d::tweenfunc::TweenType _tweenEasing;

    //! The animation update speed
    float _animationInternal;


protected:
    //! The durantion frame count will run
    int _durationTween;

    //! Current frame this process arrived, this frame is tween frame
    float _currentFrame;
    //! Frame index it the time line
    int _curFrameIndex;

    //! Next frame this process need run to
    int _nextFrameIndex;


    bool _isLoopBack;
};

}

#endif /*__CCPROCESSBASE_H__*/