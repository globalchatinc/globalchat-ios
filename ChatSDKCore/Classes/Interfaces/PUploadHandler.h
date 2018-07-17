//
//  BUploadHandler.h
//  Pods
//
//  Created by Benjamin Smiley-andrews on 07/03/2016.
//
//

#ifndef PUploadHandler_h
#define PUploadHandler_h

#define bFilePath @"bFilePath"
#define bFileName @"bFileName"

@class RXPromise;

@protocol PUploadHandler <NSObject>

-(RXPromise *) uploadFile:(NSData *)file withName: (NSString *) name mimeType: (NSString *) mimeType;

-(RXPromise *) uploadImage:(UIImage *)image thumbnail: (UIImage *) thumbnail;

@end

#endif /* PUploadHandler_h */
