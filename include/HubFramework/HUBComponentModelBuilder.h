#import <Foundation/Foundation.h>

@protocol HUBComponentImageDataBuilder;
@protocol HUBViewModelBuilder;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Protocol defining the public API for a builder that builds component model objects
 *
 *  This builder acts like a mutable model counterpart for `HUBComponentModel`, with the key
 *  difference that they are not related by inheritance.
 *
 *  All properties are briefly documented as part of this protocol, but for more extensive
 *  documentation and use case examples, see the full documentation in the `HUBComponentModel`
 *  protocol definition.
 */
@protocol HUBComponentModelBuilder <NSObject>

/// The identifier of the model that this builder is for
@property (nonatomic, copy, readonly) NSString *modelIdentifier;

/// The (namespaced) identifier of the model's component. If nil, a fallback component will be used.
@property (nonatomic, copy, nullable) NSString *componentIdentifier;

/// Any identifier for the model's content, that can be used for content tracking
@property (nonatomic, copy, nullable) NSString *contentIdentifier;

/// The index that the component would prefer to be placed at. Can be used to move components locally.
@property (nonatomic, copy, nullable) NSNumber *preferredIndex;

/// Any title that the component should render
@property (nonatomic, copy, nullable) NSString *title;

/// Any subtitle that the component should render
@property (nonatomic, copy, nullable) NSString *subtitle;

/// Any accessory title that the component should render
@property (nonatomic, copy, nullable) NSString *accessoryTitle;

/// Any longer describing text that the component should render
@property (nonatomic, copy, nullable) NSString *descriptionText;

/// A builder that can be used to construct data that describes how to render the component's "main" image
@property (nonatomic, strong, readonly) id<HUBComponentImageDataBuilder> mainImageDataBuilder;

/// A builder that can be used to construct data that describes how to render the component's background image
@property (nonatomic, strong, readonly) id<HUBComponentImageDataBuilder> backgroundImageDataBuilder;

/// Any URL that is the target of a user interaction with the component
@property (nonatomic, copy, nullable) NSURL *targetURL;

/// A builder that can be used to construct a pre-computed view model for a view that is the target of `targetURL`
@property (nonatomic, strong, readonly) id<HUBViewModelBuilder> targetInitialViewModelBuilder;

/// Any custom data that the component should use
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSObject *> *customData;

/// Any data that should be logged alongside interactions or impressions for the component
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSObject *> *loggingData;

/// Any date that is associated with the component
@property (nonatomic, strong, nullable) NSDate *date;

/**
 *  Return whether this builder contains a builder for custom image data for a certain identifier
 *
 *  @param identifier The identifier to look for
 */
- (BOOL)builderExistsForCustomImageDataWithIdentifier:(NSString *)identifier;

/**
 *  Get or create a builder for data for a custom image with a certain identifier
 *
 *  @param identifier The identifier of the image
 *
 *  @return If a builder already exists for the supplied identifier, then it's returned. Otherwise a new builder is
 *  created, which can be used to build an image data model. Since this method lazily creates a builder in case one
 *  doesn't already exist, use the `-builderExistsForImageDataWithIdentifier:` API instead if you simply wish to
 *  check for the existance of a builder. See `HUBComponentImageDataBuilder` for more information.
 */
- (id<HUBComponentImageDataBuilder>)builderForCustomImageDataWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END