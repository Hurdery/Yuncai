//
//  MJProperty.h
//  MJExtensionExample
//
//  Created by MJ Lee on 15/4/17.
//  Copyright (c) 2015年 小码哥. All rights reserved.
//  包装一个成员属性

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
@class MJType;

/**
 *  包装一个成员
 */
@interface MJProperty : NSObject
/** 成员属性 */
@property (nonatomic, assign) objc_property_t property;
/** 成员属性名 */
@property (nonatomic, readonly) NSString *name;

/** 成员变量的类型 */
@property (nonatomic, readonly) MJType *type;
/** 成员来源于哪个类（可能是父类） */
@property (nonatomic, assign) Class srcClass;

/**** 同一个成员变量 - 父类和子类的行为可能不一致（key、keys、objectClassInArray） ****/
/** 对应着字典中的key */
- (void)setKey:(NSString *)key forClass:(Class)c;
- (NSString *)keyFromClass:(Class)c;

/** 对应着字典中的多级key */
- (NSArray *)keysFromClass:(Class)c;

/** 模型数组中的模型类型 */
- (void)setObjectClassInArray:(Class)objectClass forClass:(Class)c;
- (Class)objectClassInArrayFromClass:(Class)c;
/**** 同一个成员变量 - 父类和子类的行为可能不一致（key、keys、objectClassInArray） ****/

/**
 * 设置成员变量的值
 */
- (void)setValue:(id)value forObject:(id)object;
/**
 * 得到成员变量的值
 */
- (id)valueFromObject:(id)object;

/**
 *  初始化
 */
+ (instancetype)cachedPropertyWithProperty:(objc_property_t)property;
@end
