/*
 * v4l-test: Test environment for Video For Linux Two API
 *
 *  1 Jan 2009  0.3  Added index=S32_MAX and S32_MAX+1
 * 22 Dec 2008  0.2  Test case with NULL parameter added
 * 18 Dec 2008  0.1  First release
 *
 * Written by Mrton Nmeth <nm127@freemail.hu>
 * Released under GPL
 */

void test_VIDIOC_ENUMINPUT(void);
void test_VIDIOC_ENUMINPUT_S32_MAX(void);
void test_VIDIOC_ENUMINPUT_S32_MAX_1(void);
void test_VIDIOC_ENUMINPUT_U32_MAX(void);
void test_VIDIOC_ENUMINPUT_3(void);
void test_VIDIOC_ENUMINPUT_NULL(void);
