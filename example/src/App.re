open ReasonWindow;

[@react.component]
let make = () => {
    <div>
        <FixedSizeList
            className={"fixed"}
            direction={SharedList.Ltr}
            height={200}
            itemCount={1000}
            itemSize={50}
            layout={SharedList.Vertical}
            onItemsRendered={Js.log}
            onScroll={Js.log}
            useIsScrolling={true}
            style={ReactDOMRe.Style.make(~background="red", ())}
            overscanCount={10}
            width={200}
        >
            {cellProps => <Cell cellProps/>}
        </FixedSizeList>
        <VariableSizeList
            className={"variable"}
            direction={SharedList.Ltr}
            estimatedItemSize={100}
            height={200}
            itemCount={100}
            itemSize={index => index + 50}
            layout={SharedList.Vertical}
            onItemsRendered={Js.log}
            onScroll={Js.log}
            useIsScrolling={true}
            style={ReactDOMRe.Style.make(~background="green", ())}
            overscanCount={10}
            width={200}
        >
            {cellProps => <Cell cellProps/>}
        </VariableSizeList>
    </div>
    
};